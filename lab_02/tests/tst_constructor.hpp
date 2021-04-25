#ifndef TST_CONSTRUCTOR_HPP
#define TST_CONSTRUCTOR_HPP

#include <gtest/gtest.h>
#include <iostream>

#include "vector.h"

#define EPS 1e-6

using namespace std;

TEST(contructors, defaultInt)
{
    Vector<int> a;
    EXPECT_EQ(a.is_empty(), true);
}

TEST(contructors, sizeInt)
{
    Vector<int> a(3);
    EXPECT_EQ(a.is_empty(), false);

    for (auto elem : a)
        EXPECT_EQ(elem, 0);
}

TEST(contructors, sizeDouble)
{
    Vector<double> a(3);
    EXPECT_EQ(a.is_empty(), false);

    for (auto elem : a)
        EXPECT_NEAR(elem, 0, EPS);
}

TEST(contructors, fillerInt)
{
    Vector<int> a(3, -1);
    EXPECT_EQ(a.is_empty(), false);

    for (auto elem : a)
        EXPECT_EQ(elem, -1);
}

TEST(contructors, initListInt)
{
    Vector<int> a = {1, 2, 3, 8, 2, 5, 90, -10};
    EXPECT_EQ(a.is_empty(), false);

    for (auto elem : a)
        cout << elem << endl;
}

TEST(contructors, initListChar)
{
    Vector<char> a = {'T', 'R', 'Y'};
    EXPECT_EQ(a.is_empty(), false);

    for (auto elem : a)
        cout << elem << endl;
}
#endif // TST_CONSTRUCTOR_HPP
