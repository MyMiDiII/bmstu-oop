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
}

TEST(contructors, sizeDouble)
{
    Vector<double> a(3);
    EXPECT_EQ(a.isEmpty(), false);
}

TEST(contructors, fillerInt)
{
    size_t size = 3;
    int filler = -1;
    Vector<int> a(size, filler);
    EXPECT_EQ(a.isEmpty(), false);

    for (auto elem : a)
        EXPECT_EQ(elem, -1);
}

TEST(contructors, initListInt)
{
    Vector<int> a{5, -9, 0, 13};
    EXPECT_EQ(a.isEmpty(), false);
    int arr[4] = {5, -9, 0, 13};

    int i = 0;
    for (auto elem : a)
        EXPECT_EQ(elem, arr[i++]);
}

TEST(contructors, initListChar)
{
    Vector<char> a{'T', 'R', 'Y'};
    EXPECT_EQ(a.isEmpty(), false);

    int arr[3] = {'T', 'R', 'Y'};

    int i = 0;
    for (auto elem : a)
        EXPECT_EQ(elem, arr[i++]);
}

#endif // TST_CONSTRUCTOR_HPP
