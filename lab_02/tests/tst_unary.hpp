#ifndef TST_UNARY_HPP
#define TST_UNARY_HPP

#include <gtest/gtest.h>

#include "vector.h"

TEST(unary, at)
{
    Vector<int> a = {3, 2, 1};
    int b = a.at(2);

    EXPECT_EQ(b, 1);
}

TEST(unare, badAt)
{
    Vector<int> a = {3, 2, 1};
    EXPECT_ANY_THROW(a.at(3));
}

TEST(unare, atChange)
{
    Vector<int> a = {3, 2, 1};
    a.at(0) = 1;
    int tmp[3] = {1, 2, 1};
    int i = 0;

    for (auto elem : a)
        EXPECT_EQ(elem, tmp[i++]);
}

TEST(unare, neg)
{
    Vector<int> a = {3, -2, 0};
    Vector<int> res(a.neg());

    int tmp[3] = {-3, 2, 0};
    int tmpA[3] = {3, -2, 0};

    int i = 0;
    for (auto elem : a)
        EXPECT_EQ(elem, tmpA[i++]);

    i = 0;
    for (auto elem : res)
        EXPECT_EQ(elem, tmp[i++]);
}

#endif // TST_UNARY_HPP
