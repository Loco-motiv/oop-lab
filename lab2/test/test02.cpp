#include <gtest/gtest.h>
#include "eleven.h"
TEST(test_00, Constructors_and_Equal_sign_TRUE) 
{
    Eleven t1 { 'A', '0', '4'};
    Eleven t2();
    Eleven t3("A04");
    Eleven t4(std::string("A324"));
    Eleven t5(t4);
    ASSERT_TRUE((t1 == t3) and (t4 == t5));
}
TEST(test_01, Addition_TRUE) 
{
    Eleven ta { "9179" };
    Eleven tb { "A09A" };
    Eleven tc { "18268" };
    ASSERT_EQ(ta + tb, tc);

}
TEST(test_02, Subtraction_TRUE)
{
    Eleven t1 { '4', 'A', '4' };
    Eleven t2 { '2', '3' };

    Eleven t3 (std::string("481"));
    Eleven t4 (t1 - t2);
    ASSERT_EQ(t4, t3);
}
TEST(test_03, More_than_TRUE)
{
    Eleven t1 (std::string("100"));
    Eleven t2 (std::string("AA"));
    Eleven t3 (std::string("999"));
    Eleven t4 (std::string("A00"));
    ASSERT_TRUE((t1 > t2) and (t4 > t3));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}