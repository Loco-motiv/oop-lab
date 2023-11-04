#include <gtest/gtest.h>
#include "figure.h"
#include "hexagon.h"
#include "octagon.h"
#include "pentagon.h"
#include "array.h"
#include <memory>
#include <math.h>
#include <iostream>

TEST(HexagonTest, AreaCalculation) {
    Point<double> H1(0.0, 0.0);
    Point<double> H2(2.0, 0.0);
    Point<double> H3(3.0, 2.0);
    Point<double> H4(2.0, 4.0);
    Point<double> H5(0.0, 4.0);
    Point<double> H6(-1.0, 2.0);
    std::shared_ptr<Hexagon<double>> hexagon = std::make_shared<Hexagon<double>>(H1,H2,H3,H4,H5,H6);

    ASSERT_NEAR(10.3923, hexagon->operator double(), 10e-5);
}

TEST(HexagonTest, CenterCalculation) {
    Point<double> H1(0.0, 0.0);
    Point<double> H2(2.0, 0.0);
    Point<double> H3(3.0, 2.0);
    Point<double> H4(2.0, 4.0);
    Point<double> H5(0.0, 4.0);
    Point<double> H6(-1.0, 2.0);
    std::shared_ptr<Hexagon<double>> hexagon = std::make_shared<Hexagon<double>>(H1,H2,H3,H4,H5,H6);

    ASSERT_EQ(Point<double>(1, 2), hexagon->centre());
}

TEST(Octagon, AreaCalculation) {
    Point<double> O1(0.0, 0.0);
    Point<double> O2(2.0, 0.0);
    Point<double> O3(4.0, 2.0);
    Point<double> O4(4.0, 4.0);
    Point<double> O5(2.0, 6.0);
    Point<double> O6(0.0, 6.0);
    Point<double> O7(-2.0, 4.0);
    Point<double> O8(-2.0, 2.0);
    std::shared_ptr<Octagon<double>> octagon = std::make_shared<Octagon<double>>(O1, O2, O3, O4, O5, O6, O7, O8);

    ASSERT_NEAR(19.3137, octagon->operator double(), 10e-5);
}

TEST(Octagon, CenterCalculation) {
    Point<double> O1(0.0, 0.0);
    Point<double> O2(2.0, 0.0);
    Point<double> O3(4.0, 2.0);
    Point<double> O4(4.0, 4.0);
    Point<double> O5(2.0, 6.0);
    Point<double> O6(0.0, 6.0);
    Point<double> O7(-2.0, 4.0);
    Point<double> O8(-2.0, 2.0);
    std::shared_ptr<Octagon<double>> octagon = std::make_shared<Octagon<double>>(O1, O2, O3, O4, O5, O6, O7, O8);

    ASSERT_EQ(Point<double>(1, 3), octagon->centre());
}

TEST(PentagonTest, AreaCalculation) {
    Point<double> P1(8.0, 0.0);
    Point<double> P2(12.0, 2.0);
    Point<double> P3(10.0, 6.0);
    Point<double> P4(6.0, 6.0);
    Point<double> P5(4.0, 2.0);
    std::shared_ptr<Pentagon<double>> pentagon = std::make_shared<Pentagon<double>>(P1, P2, P3, P4, P5);

    ASSERT_NEAR(34.4095, pentagon->operator double(), 10e-5);
}

TEST(PentagonTest, CenterCalculation) {
    Point<double> P1(8.0, 0.0);
    Point<double> P2(12.0, 2.0);
    Point<double> P3(10.0, 6.0);
    Point<double> P4(6.0, 6.0);
    Point<double> P5(4.0, 2.0);
    std::shared_ptr<Pentagon<double>> pentagon = std::make_shared<Pentagon<double>>(P1, P2, P3, P4, P5);

    ASSERT_EQ(Point<double>(8.0, 3.2), pentagon->centre());
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}