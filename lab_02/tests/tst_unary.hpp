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

TEST(unary, badAt)
{
    Vector<int> a = {3, 2, 1};
    EXPECT_ANY_THROW(a.at(3));
}

TEST(unary, atChange)
{
    Vector<int> a = {3, 2, 1};
    a.at(0) = 1;
    int tmp[3] = {1, 2, 1};
    int i = 0;

    for (auto elem : a)
        EXPECT_EQ(elem, tmp[i++]);
}

TEST(unary, neg)
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

TEST(unary, length)
{
    Vector<int> a = {1, -2, 2};

    EXPECT_NEAR(a.length(), 3, EPS);
}

TEST(unary, badLength)
{
    Vector<int> a(0);

    EXPECT_ANY_THROW(a.length());
}

TEST(unary, zeroAngle)
{
    Vector<int> i = {1, 0, 0};
    Vector<int> a = {2, 0, 0};

    EXPECT_NEAR(i.angle(a), 0, EPS);
}

TEST(unary, piDiv2Angle)
{
    Vector<int> i = {1, 0, 0};
    Vector<int> j = {0, 1, 0};

    EXPECT_NEAR(i.angle(j), M_PI / 2, EPS);
}

TEST(unary, piAngle)
{
    Vector<int> i = {1, 0, 0};
    Vector<int> j = {-1, 0, 0};

    EXPECT_NEAR(i.angle(j), M_PI, EPS);
}

TEST(unary, generalAngle)
{
    Vector<int> i = {1, 2, -2, 0};
    Vector<int> j = {0, 3, 0, -4};

    EXPECT_NEAR(i.angle(j), 1.15927948, EPS);
}

TEST(unary, isZeroInt)
{
    Vector<int> i = {0, 0, 0};

    EXPECT_EQ(i.isZero(), true);
}

TEST(unary, isZeroDouble)
{
    Vector<double> i = {0, 0, 0};

    EXPECT_EQ(i.isZero(), true);
}

TEST(unary, isNotZero)
{
    Vector<double> i = {1};

    EXPECT_EQ(i.isZero(), false);
}

#endif // TST_UNARY_HPP
