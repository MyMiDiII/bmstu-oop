#ifndef TST_CONSTRUCTOR_HPP
#define TST_CONSTRUCTOR_HPP

#include <gtest/gtest.h>
#include <iostream>

#include "vector.h"

TEST(contructors, defaultInt)
{
    Vector<int> a;
    EXPECT_EQ(a.is_empty(), true);
}

#endif // TST_CONSTRUCTOR_HPP
