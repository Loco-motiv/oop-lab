#include <gtest/gtest.h>
#include "npc.h"
#include "dragon.h"
#include "knight_errant.h"
#include "elf.h"

TEST(FightTest, Knight_ErrantAttackDragon) {
    std::shared_ptr<NPC> dragon = std::make_shared<Dragon>(0, 0);
    std::shared_ptr<NPC> knight_Errant = std::make_shared<Knight_Errant>(1, 1);
    bool success = dragon->accept(knight_Errant);
    ASSERT_TRUE(success);
}

TEST(FightTest, DragonAttackAll) {
    std::shared_ptr<NPC> dragon1 = std::make_shared<Dragon>(0, 0);
    std::shared_ptr<NPC> dragon2 = std::make_shared<Dragon>(3, 3);
    
    std::shared_ptr<NPC> knight_Errant = std::make_shared<Knight_Errant>(1, 1);
    std::shared_ptr<NPC> elf = std::make_shared<Elf>(2, 2);
    bool success = knight_Errant->accept(dragon1) and elf->accept(dragon1) and dragon2->accept(dragon1);
    ASSERT_TRUE(success);
}

TEST(FightTest, ElfAttackKnight_Errant) {
    std::shared_ptr<NPC> knight_Errant = std::make_shared<Knight_Errant>(1, 1);
    std::shared_ptr<NPC> elf = std::make_shared<Elf>(2, 2);
    bool success = knight_Errant->accept(elf);
    ASSERT_TRUE(success);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}