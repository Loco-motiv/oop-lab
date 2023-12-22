#pragma once

#include <iostream>
#include <memory>
#include <cstring>
#include <string>
#include <random>
#include <fstream>
#include <set>
#include <math.h>
#include <shared_mutex>

struct NPC;
struct Dragon;
struct Knight_Errant;
struct Elf;
struct Visitor;
using set_t = std::set<std::shared_ptr<NPC>>;

enum NpcType
{
    Unknown = 0,
    DragonType = 1,
    Knight_ErrantType = 2,
    ElfType = 3
};

struct IFightObserver{
    virtual void on_fight(const std::shared_ptr<NPC> attacker,const std::shared_ptr<NPC> defender,bool win) = 0;
};

struct NPC : public std::enable_shared_from_this<NPC>
{

private:
    std::mutex mtx;

    NpcType type;
    int x{0};
    int y{0};
    bool alive{true};

    std::vector<std::shared_ptr<IFightObserver>> observers;

public:
    NPC(NpcType t, int _x, int _y);
    NPC(NpcType t, std::istream &is);

    void subscribe(std::shared_ptr<IFightObserver>observer );
    void fight_notify(const std::shared_ptr<NPC> defender,bool win);
    virtual bool is_close(const std::shared_ptr<NPC> &other, size_t distance) const;

    virtual bool fight_Dragon(std::shared_ptr<Dragon> other) = 0;
    virtual bool fight_Knight_Errant(std::shared_ptr<Knight_Errant> other) = 0;
    virtual bool fight_Elf(std::shared_ptr<Elf> other) = 0;
    virtual void print() = 0;

    std::pair<int, int> position();
    NpcType get_type();

    virtual void save(std::ostream &os);
    
    virtual bool accept(std::shared_ptr<NPC> attacker) = 0;

    friend std::ostream &operator<<(std::ostream &os, NPC &npc);

    void move(int shift_x, int shift_y, int max_x, int max_y);

    bool is_alive();
    void must_die();
};