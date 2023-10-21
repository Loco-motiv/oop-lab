#include <gtest/gtest.h>
#include "figure.h"
#include "hexagon.h"
#include "octagon.h"
#include "pentagon.h"
#include <vector>
#include <math.h>

TEST(octagon, Area) {
    std::vector<Point> cords = {Point(0, 0), Point(10, 0), Point(10 + 5 * std::sqrt(2), 5* std::sqrt(2)), Point(10 + 5 * std::sqrt(2), 10 + 5 * std::sqrt(2)), Point(10, 10 + 10 * std::sqrt(2)), Point(0, 10 + 10 * std::sqrt(2)), Point(-5 * std::sqrt(2), 10 + 5 * std::sqrt(2)), Point(-5 * std::sqrt(2), 5 * std::sqrt(2))};
    Octagon octagon1(cords);
    EXPECT_DOUBLE_EQ(octagon1.area(), 482.84271247461896);
}

TEST(octagon, Centre) {
    std::vector<Point> cords = {Point(0, 0), Point(10, 0), Point(10 + 5 * std::sqrt(2), 5* std::sqrt(2)), Point(10 + 5 * std::sqrt(2), 10 + 5 * std::sqrt(2)), Point(10, 10 + 10 * std::sqrt(2)), Point(0, 10 + 10 * std::sqrt(2)), Point(-5 * std::sqrt(2), 10 + 5 * std::sqrt(2)), Point(-5 * std::sqrt(2), 5 * std::sqrt(2))};
    Octagon octagon1(cords);
    Point centre = octagon1.centre();
    EXPECT_DOUBLE_EQ(centre._x, 40);
    EXPECT_DOUBLE_EQ(centre._y, 96.568542494923804);
}

TEST(octagon, Equals)
{
    std::vector<Point> cords1 = {Point(0, 0), Point(10, 0), Point(10 + 5 * std::sqrt(2), 5* std::sqrt(2)), Point(10 + 5 * std::sqrt(2), 10 + 5 * std::sqrt(2)), Point(10, 10 + 10 * std::sqrt(2)), Point(0, 10 + 10 * std::sqrt(2)), Point(-5 * std::sqrt(2), 10 + 5 * std::sqrt(2)), Point(-5 * std::sqrt(2), 5 * std::sqrt(2))};
    std::vector<Point> cords2 = {Point(0, 0), Point(10, 0), Point(10 + 5 * std::sqrt(2), 5* std::sqrt(2)), Point(10 + 5 * std::sqrt(2), 10 + 5 * std::sqrt(2)), Point(10, 10 + 10 * std::sqrt(2)), Point(0, 10 + 10 * std::sqrt(2)), Point(-5 * std::sqrt(2), 10 + 5 * std::sqrt(2)), Point(-5 * std::sqrt(2), 5 * std::sqrt(2))};
    Octagon octagon1(cords1);
    Octagon octagon2(cords2);
    ASSERT_TRUE(octagon1 == octagon2);
}

// Тесты с другими классами по аналогии, т.к. отличаются от Octagon только формулами площади и количеством вершин в векторе вершин

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}