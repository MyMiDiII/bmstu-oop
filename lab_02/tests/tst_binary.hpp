#ifndef TST_BINARY_HPP
#define TST_BINARY_HPP

#include <gtest/gtest.h>

#include "vector.h"

TEST(binary, vecSum)
{
    Vector<int> a = {-100, 0, 6};
    Vector<int> b = {200, 4, -5};

    Vector<int> res(a.vecSum(b));

    int tmp_a[3] = {-100, 0, 6};
    int tmp[3] = {100, 4, 1};

    int i = 0;
    for (auto elem : a)
        EXPECT_EQ(elem, tmp_a[i++]);

    i = 0;
    for (auto elem : res)
        EXPECT_EQ(elem, tmp[i++]);
}

TEST(binary, eqVecSum)
{
    Vector<int> a = {-100, 0, 6};
    Vector<int> b = {200, 4, -5};

    Vector<int> res(a.eqVecSum(b));

    int tmp[3] = {100, 4, 1};

    int i = 0;
    for (auto elem : a)
        EXPECT_EQ(elem, tmp[i++]);

    i = 0;
    for (auto elem : res)
        EXPECT_EQ(elem, tmp[i++]);
}

TEST(binary, badVecSum)
{
    Vector<int> a = {-100, 0, 6};
    Vector<int> b = {200, 4};

    EXPECT_ANY_THROW(a.vecSum(b));
}

TEST(binary, badEqVecSum)
{
    Vector<int> a = {-100, 0, 6};
    Vector<int> b = {200, 4};

    EXPECT_ANY_THROW(a.eqVecSum(b));
}

TEST(binary, vecDiff)
{
    Vector<int> a = {-100, 0, 6};
    Vector<int> b = {200, 4, -5};

    Vector<int> res(a.vecDiff(b));

    int tmp_a[3] = {-100, 0, 6};
    int tmp[3] = {-300, -4, 11};

    int i = 0;
    for (auto elem : a)
        EXPECT_EQ(elem, tmp_a[i++]);

    i = 0;
    for (auto elem : res)
        EXPECT_EQ(elem, tmp[i++]);
}

TEST(binary, eqVecDiff)
{
    Vector<int> a = {-100, 0, 6};
    Vector<int> b = {200, 4, -5};

    Vector<int> res(a.eqVecDiff(b));

    int tmp[3] = {-300, -4, 11};

    int i = 0;
    for (auto elem : a)
        EXPECT_EQ(elem, tmp[i++]);

    i = 0;
    for (auto elem : res)
        EXPECT_EQ(elem, tmp[i++]);
}

TEST(binary, badVecDiff)
{
    Vector<int> a = {-100, 0, 6};
    Vector<int> b = {200, 4};

    EXPECT_ANY_THROW(a.vecDiff(b));
}

TEST(binary, badEqVecDiff)
{
    Vector<int> a = {-100, 0, 6};
    Vector<int> b = {200, 4};

    EXPECT_ANY_THROW(a.eqVecDiff(b));
}

#endif // TST_BINARY_HPP
