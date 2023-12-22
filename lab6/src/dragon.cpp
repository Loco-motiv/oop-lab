#include "dragon.h"
#include "knight_errant.h"
#include "elf.h"

Dragon::Dragon(int x, int y) : NPC(DragonType, x, y) {}
Dragon::Dragon(std::istream &is) : NPC(DragonType, is) {}

void Dragon::print()
{
    std::cout << *this;
}

bool Dragon::accept(std::shared_ptr<NPC> attacker) {
    return attacker->fight_Dragon(std::dynamic_pointer_cast<Dragon>(shared_from_this()));
}

bool Dragon::fight_Dragon(std::shared_ptr<Dragon> other) 
{
    fight_notify(other, false);
    return true;
}

bool Dragon::fight_Knight_Errant(std::shared_ptr<Knight_Errant> other) 
{
    fight_notify(other, false);
    return true;
}

bool Dragon::fight_Elf(std::shared_ptr<Elf> other) 
{
    fight_notify(other, false);
    return true;
}

void Dragon::save(std::ostream &os) 
{
    os << DragonType << std::endl;
    NPC::save(os);
}

std::ostream &operator<<(std::ostream &os, Dragon &dragon)
{
    os << "dragon: " << *static_cast<NPC *>(&dragon) << std::endl;
    return os;
}