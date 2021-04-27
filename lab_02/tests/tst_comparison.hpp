#ifndef TST_COMPARISON_HPP
#define TST_COMPARISON_HPP

#include <gtest/gtest.h>

#include "vector.h"

TEST(comparison_operators, equal)
{
    Vector<int> a = {-5, 6, 0};
    Vector<int> b = {-5, 6, 0};

    EXPECT_EQ((a == b), true);
}

TEST(comparison_operators, emptyEqual)
{
    Vector<int> a(0);
    Vector<int> b(0);

    EXPECT_EQ((a == b), true);
}

TEST(comparison_operators, notEqual)
{
    Vector<int> a = {-5, 6, 0};
    Vector<int> b = {12, 3, 5};

    EXPECT_EQ((a == b), false);
}

TEST(comparison_operators, notEqualBySizes)
{
    Vector<int> a = {12, 3, 5, 4};
    Vector<int> b = {12, 3, 5};

    EXPECT_EQ((a == b), false);
}

TEST(comparison_operators, nequal)
{
    Vector<int> a = {-5, 6, 0};
    Vector<int> b = {-5, 6, 0};

    EXPECT_EQ((a != b), false);
}

TEST(comparison_operators, notNEqual)
{
    Vector<int> a = {-5, 6, 0};
    Vector<int> b = {12, 3, 5};

    EXPECT_EQ((a != b), true);
}

TEST(comparison_operators, notNEqualBySizes)
{
    Vector<int> a = {12, 3, 5, 4};
    Vector<int> b = {12, 3, 5};

    EXPECT_EQ((a != b), true);
}

#endif // TST_COMPARISON_HPP
