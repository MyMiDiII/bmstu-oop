#ifndef TST_CONSTRUCTOR_HPP
#define TST_CONSTRUCTOR_HPP

#include <gtest/gtest.h>
#include <iostream>

#include "vector.h"

using namespace std;

TEST(contructors, defaultInt)
{
    Vector<int> a;
    EXPECT_EQ(a.isEmpty(), true);
}

TEST(contructors, sizeInt)
{
    Vector<int> a(3);
    EXPECT_EQ(a.isEmpty(), false);

    //for (auto elem : a)
    //  EXPECT_EQ(elem, 0);
}

TEST(contructors, sizeDouble)
{
    Vector<double> a(3);
    EXPECT_EQ(a.isEmpty(), false);

    //for (auto elem : a)
    //  EXPECT_NEAR(elem, 0, EPS);
}

TEST(contructors, fillerInt)
{
    Vector<int> a(3, -1);
    EXPECT_EQ(a.isEmpty(), false);

    for (auto elem : a)
        EXPECT_EQ(elem, -1);
}

TEST(contructors, initListInt)
{
    Vector<int> a = {5, -9, 0, 13};
    EXPECT_EQ(a.isEmpty(), false);
    int arr[4] = {5, -9, 0, 13};

    int i = 0;
    for (auto elem : a)
        EXPECT_EQ(elem, arr[i++]);
}

TEST(contructors, initListChar)
{
    Vector<char> a = {'T', 'R', 'Y'};
    EXPECT_EQ(a.isEmpty(), false);

    int arr[3] = {'T', 'R', 'Y'};

    int i = 0;
    for (auto elem : a)
        EXPECT_EQ(elem, arr[i++]);
}

#endif // TST_CONSTRUCTOR_HPP
