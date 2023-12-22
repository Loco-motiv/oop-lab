#pragma once
#include "npc.h"

struct Elf : public NPC
{
    Elf(int x, int y);
    Elf(std::istream &is);

    void print() override;
    void save(std::ostream &os) override;

    bool fight_Elf(std::shared_ptr<Elf> other) override;
    bool fight_Knight_Errant(std::shared_ptr<Knight_Errant> other) override;
    bool fight_Dragon(std::shared_ptr<Dragon> other) override;

    bool accept(std::shared_ptr<NPC> attacker) override;

    friend std::ostream &operator<<(std::ostream &os, Elf &Elf);
};