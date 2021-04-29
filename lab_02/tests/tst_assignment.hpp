#ifndef TST_ASSIGNMENT_HPP
#define TST_ASSIGNMENT_HPP

#include <gtest/gtest.h>

#include "vector.h"

TEST(assignment, initList)
{
    Vector<int> a(4);
    a = {5, -9, 0, 13};
    EXPECT_EQ(a.isEmpty(), false);
    int arr[4] = {5, -9, 0, 13};

    int i = 0;
    for (auto elem : a)
        EXPECT_EQ(elem, arr[i++]);
}

TEST(assignment, vector)
{
    Vector<int> a = {5, -9, 0, 13};
    EXPECT_EQ(a.isEmpty(), false);

    Vector<int> b = {1, 2, 3, 5};
    b = a;
    int arr[4] = {5, -9, 0, 13};

    int i = 0;
    for (auto elem : b)
        EXPECT_EQ(elem, arr[i++]);
}

TEST(assignment, vectorCopy)
{
    Vector<int> a = {5, -9, 0, 13};
    EXPECT_EQ(a.isEmpty(), false);

    Vector<int> b = {1, 2, 3};
    b = a;
    int arr[4] = {5, -9, 0, 13};

    int i = 0;
    for (auto elem : b)
        EXPECT_EQ(elem, arr[i++]);
}

#endif // TST_ASSIGNMENT_HPP
