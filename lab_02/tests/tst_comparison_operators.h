#ifndef TST_COMPARISON_OPERATORS_H
#define TST_COMPARISON_OPERATORS_H

#include <gtest/gtest.h>

#include "vector.h"

TEST(comparison_operators, equal)
{
    Vector<int> a = {-5, 6, 0};
    Vector<int> b = {-5, 6, 0};

    EXPECT_EQ((a == b), true);
}

TEST(comparison_operators, not_equal)
{
    Vector<int> a = {-5, 6, 0};
    Vector<int> b = {12, 3, 5};

    EXPECT_EQ((a == b), false);
}

#endif // TST_COMPARISON_OPERATORS_H
