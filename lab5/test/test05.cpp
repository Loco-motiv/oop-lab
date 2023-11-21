#include <gtest/gtest.h>
#include <map>
#include <allocator.h>
#include <forwardlist.h>
#include <iostream>

TEST(ForwardListTest, Push_front) {
    ForwardList<int, Allocator<int>> n;

    n.push_front(1);
    n.push_front(2);
    n.push_front(3);
    n.push_front(4);
    n.push_front(5);
    n.push_front(6);
    
    ASSERT_EQ(3, n[3]);
}

TEST(ForwardListTest, Size) {
    ForwardList<int, Allocator<int>> n;

    n.push_front(1);
    n.push_front(2);
    n.push_front(3);
    n.push_front(4);
    n.push_front(5);

    ASSERT_EQ(5, n.size());
}

TEST(ForwardListTest, Eraze) {
    ForwardList<int, Allocator<int>> n;

    n.push_front(1);
    n.push_front(2);
    n.push_front(3);
    n.push_front(4);
    n.push_front(5);
    n.push_front(6);

    n.erase(n.begin());

    ASSERT_EQ(5, n.size());
}

TEST(ForwardListTest, Insert) {
    
    ForwardList<int, Allocator<int>> n;

    n.push_front(1);
    n.push_front(2);
    n.push_front(3);
    n.push_front(4);
    n.push_front(5);
    n.push_front(6);

    ForwardList<int, Allocator<int>>::ListIterator it = n.begin();
    ++it;

    n.insert(it, 10);

    ASSERT_EQ(10, n[1]);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}