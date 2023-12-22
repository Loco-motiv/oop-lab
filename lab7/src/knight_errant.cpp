#include "elf.h"
#include "knight_errant.h"
#include "dragon.h"

Knight_Errant::Knight_Errant(int x, int y) : NPC(Knight_ErrantType, x, y) {}
Knight_Errant::Knight_Errant(std::istream &is) : NPC(Knight_ErrantType, is) {}

void Knight_Errant::print()
{
    std::cout << *this;
}

void Knight_Errant::save(std::ostream &os)
{
    os << Knight_ErrantType << std::endl;
    NPC::save(os);
}

bool Knight_Errant::accept(std::shared_ptr<NPC> attacker) {
    return attacker->fight_Knight_Errant(std::dynamic_pointer_cast<Knight_Errant>(shared_from_this()));
}

bool Knight_Errant::fight_Dragon(std::shared_ptr<Dragon> other)
{
    fight_notify(other, true);
    return true;
}

bool Knight_Errant::fight_Knight_Errant(std::shared_ptr<Knight_Errant> other)
{
    fight_notify(other, false);
    return false;
}

bool Knight_Errant::fight_Elf(std::shared_ptr<Elf> other)
{
    fight_notify(other, false);
    return false;
}

std::ostream &operator<<(std::ostream &os, Knight_Errant &knight_Errant)
{
    os << "knight_Errant: " << *static_cast<NPC *>(&knight_Errant) << std::endl;
    return os;
}