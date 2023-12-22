#include "npc.h"
#include "dragon.h"
#include "knight_errant.h"
#include "elf.h"
#include <sstream>
#include <atomic>
#include <thread>
#include <mutex>
#include <chrono>
#include <queue>
#include <optional>
#include <array>

using namespace std::chrono_literals;
std::mutex print_mutex;

class TextObserver : public IFightObserver
{
private:
    TextObserver(){};

public:
    static std::shared_ptr<IFightObserver> get()
    {
        static TextObserver instance;
        return std::shared_ptr<IFightObserver>(&instance, [](IFightObserver *) {});
    }

    void on_fight(const std::shared_ptr<NPC> attacker, const std::shared_ptr<NPC> defender, bool win) override
    {
        if (win)
        {
            std::cout << std::endl
                      << "Murder --------" << std::endl;
            attacker->print();
            defender->print();
        }
    }
};

std::shared_ptr<NPC> factory(std::istream &is)
{
    std::shared_ptr<NPC> result;
    int type{0};
    if (is >> type)
    {
        switch (type)
        {
        case DragonType:
            result = std::make_shared<Dragon>(is);
            break;
        case ElfType:
            result = std::make_shared<Elf>(is);
            break;
        case Knight_ErrantType:
            result = std::make_shared<Knight_Errant>(is);
            break;
        }
    }
    else
        std::cerr << "unexpected NPC type:" << type << std::endl;

    if (result)
        result->subscribe(TextObserver::get());

    return result;
}

std::shared_ptr<NPC> factory(NpcType type, int x, int y)
{
    std::shared_ptr<NPC> result;
    switch (type)
    {
    case DragonType:
        result = std::make_shared<Dragon>(x, y);
        break;
    case ElfType:
        result = std::make_shared<Elf>(x, y);
        break;
    case Knight_ErrantType:
        result = std::make_shared<Knight_Errant>(x, y);
        break;
    default:
        break;
    }
    if (result)
        result->subscribe(TextObserver::get());

    return result;
}

// save array to file
void save(const set_t &array, const std::string &filename)
{
    std::ofstream fs(filename);
    fs << array.size() << std::endl;
    for (auto &n : array)
        n->save(fs);
    fs.flush();
    fs.close();
}

set_t load(const std::string &filename)
{
    set_t result;
    std::ifstream is(filename);
    if (is.good() && is.is_open())
    {
        int count;
        is >> count;
        for (int i = 0; i < count; ++i)
            result.insert(factory(is));
        is.close();
    }
    else
        std::cerr << "Error: " << std::strerror(errno) << std::endl;
    return result;
}

std::ostream &operator<<(std::ostream &os, const set_t &array)
{
    for (auto &n : array)
        n->print();
    return os;
}

set_t fight(const set_t &array, size_t distance)
{
    set_t dead_list;

    for (const auto &attacker : array)
        for (const auto &defender : array)
            if ((attacker != defender) && (attacker->is_close(defender, distance)))
            {
                bool success = defender->accept(attacker);
                if (success)
                    dead_list.insert(defender);
            }

    return dead_list;
}

struct print : std::stringstream
{
    ~print()
    {
        static std::mutex mtx;
        std::lock_guard<std::mutex> lck(print_mutex);
        std::cout << this->str();
        std::cout.flush();
    }
};

struct FightEvent
{
    std::shared_ptr<NPC> attacker;
    std::shared_ptr<NPC> defender;
};

class FightManager
{
private:
    std::queue<FightEvent> events;
    std::shared_mutex mtx;

    FightManager() {}

public:
    static FightManager &get()
    {
        static FightManager instance;
        return instance;
    }

    void add_event(FightEvent &&event)
    {
        std::lock_guard<std::shared_mutex> lock(mtx);
        events.push(event);
    }

    void operator()()
    {
        while (true)
        {
            {
                std::optional<FightEvent> event;

                {
                    std::lock_guard<std::shared_mutex> lock(mtx);
                    if (!events.empty())
                    {
                        event = events.back();
                        events.pop();
                    }
                }

                if (event)
                {
                    try
                    {
                        if (event->attacker->is_alive())
                            if (event->defender->is_alive())
                                if (event->defender->accept(event->attacker))
                                    event->defender->must_die();
                    }
                    catch (...)
                    {
                        std::lock_guard<std::shared_mutex> lock(mtx);
                        events.push(*event);
                    }
                }
                else
                    std::this_thread::sleep_for(100ms);
            }
        }
    }
};

int main()
{
    set_t array;
    std::mutex mtx;
    std::atomic<bool> gameOver(false);
    const int MAX_X{100};
    const int MAX_Y{100};
    const int DISTANCE_KILL_DRAGON{30};
    const int DISTANCE_MOVE_DRAGON{50};
    const int DISTANCE_KILL_KNIGHT_ERRANT{10};
    const int DISTANCE_MOVE_KNIGHT_ERRANT{30};
    const int DISTANCE_MOVE_ELF{10};
    const int DISTANCE_KILL_ELF{50};

    std::cout << "Generating ..." << std::endl;
    for (size_t i = 0; i < 50; ++i)
        array.insert(factory(NpcType(std::rand() % 3 + 1),
                             std::rand() % MAX_X,
                             std::rand() % MAX_Y));
    std::cout << "Starting list:" << std::endl
              << array;

    std::thread fight_thread(std::ref(FightManager::get()));

    std::thread move_thread([&array, MAX_X, MAX_Y]()
                            {
            while (true)
            {
                // move phase
                for (std::shared_ptr<NPC> npc : array)
                {
                        if(npc->is_alive()){
                            int shift_x, shift_y;
                           switch (npc->get_type())
                           {
                            case DragonType:
                                shift_x = DISTANCE_MOVE_DRAGON;
                                shift_y = DISTANCE_MOVE_DRAGON;
                                break;
                            case Knight_ErrantType:
                                shift_x = DISTANCE_MOVE_KNIGHT_ERRANT;
                                shift_y = DISTANCE_MOVE_KNIGHT_ERRANT;
                                break;
                            case ElfType:
                                shift_x = DISTANCE_MOVE_ELF;
                                shift_y = DISTANCE_MOVE_ELF;
                                break;
                            default:
                                break;
                            }
                            npc->move(shift_x, shift_y, MAX_X, MAX_Y);
                        }
                }
                // lets fight
                for (std::shared_ptr<NPC> npc : array)
                    for (std::shared_ptr<NPC> other : array)
                        if (other != npc)
                            if (npc->is_alive())
                            {
                                if (other->is_alive())
                                {
                                    int DISTANCE;
                                    switch (npc->get_type())
                                    {
                                    case DragonType:
                                        DISTANCE = DISTANCE_KILL_DRAGON;
                                        break;
                                    case Knight_ErrantType:
                                        DISTANCE = DISTANCE_KILL_KNIGHT_ERRANT;
                                        break;
                                    case ElfType:
                                        DISTANCE = DISTANCE_KILL_ELF;
                                        break;
                                    default:
                                        break;
                                    }
                                    if (npc->is_close(other, DISTANCE))
                                    {
                                        FightManager::get().add_event({npc, other});
                                    }
                                }
                            }
                            std::this_thread::sleep_for(1s);
            } });
    while (true)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::lock_guard<std::mutex> lock(mtx);
        const int grid{20}, step_x{MAX_X / grid}, step_y{MAX_Y / grid};
        {
            std::array<char, grid * grid> fields{0};
            for (std::shared_ptr<NPC> npc : array)
            {
                auto [x, y] = npc->position();
                int i = x / step_x;
                int j = y / step_y;

                if (npc->is_alive())
                {
                    switch (npc->get_type())
                    {
                    case DragonType:
                        fields[i + grid * j] = 'D';
                        break;
                    case Knight_ErrantType:
                        fields[i + grid * j] = 'K';
                        break;
                    case ElfType:
                        fields[i + grid * j] = 'E';
                        break;
                    default:
                        break;
                    }
                }
                else
                    fields[i + grid * j] = '.';
            }

            std::lock_guard<std::mutex> lck(print_mutex);
            for (int j = 0; j < grid; ++j)
            {
                for (int i = 0; i < grid; ++i)
                {
                    char c = fields[i + j * grid];
                    if (c != 0)
                        std::cout << "[" << c << "]";
                    else
                        std::cout << "[ ]";
                }
                std::cout << std::endl;
            }
            std::cout << std::endl;
        }
        std::this_thread::sleep_for(1s);
    };

    std::thread gameTimer([&array]()
                          {
        std::this_thread::sleep_for(std::chrono::seconds(30));
        std::cout << "Игра завершена! Список выживших NPC:" << std::endl;
        for (std::shared_ptr<NPC> npc : array) {
            if (npc->is_alive()) {
                auto [x, y] = npc->position();
                std::cout << "NPC на позиции " << x << "," << y << " остался жив." << std::endl;
            }
        }
        std::exit(0); });

    move_thread.join();
    fight_thread.join();
    gameTimer.join();

    return 0;
}