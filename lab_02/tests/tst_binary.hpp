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

TEST(binary, byNumProd)
{
    Vector<double> a = {5.1, -6, 0};
    Vector<double> res(a.byNumProd(-4));

    double tmp[3] = {-20.4, 24, 0};
    double tmpA[3] = {5.1, -6, 0};

    int i = 0;
    for (auto elem : a)
        EXPECT_NEAR(elem, tmpA[i++], EPS);

    i = 0;
    for (auto elem : res)
        EXPECT_NEAR(elem, tmp[i++], EPS);
}

TEST(binary, eqByNumProd)
{
    Vector<double> a = {5.1, -6, 0};
    Vector<double> res(a.eqByNumProd(-4));

    double tmp[3] = {-20.4, 24, 0};

    int i = 0;
    for (auto elem : a)
        EXPECT_NEAR(elem, tmp[i++], EPS);

    i = 0;
    for (auto elem : res)
        EXPECT_NEAR(elem, tmp[i++], EPS);
}

TEST(binary, scalarProd)
{
    Vector<int> a = {3, 0, -7, 5, -1};
    Vector<int> b = {-3, 0, -7, 1, 8};

    EXPECT_EQ(a.scalarProd(b), 37);
}

TEST(binary, vectorProd)
{
    Vector<int> a = {-3, 2, -1};
    Vector<int> b = {1, 0, 2};
    Vector<int> res(a.vectorProd(b));

    int tmp[3] = {4, 5, -2};
    int tmpA[3] = {-3, 2, -1};

    int i = 0;
    for (auto elem : a)
        EXPECT_EQ(elem, tmpA[i++]);

    i = 0;
    for (auto elem : res)
        EXPECT_EQ(elem, tmp[i++]);
}

TEST(binary, eqVectorProd)
{
    Vector<int> a = {-3, 2, -1};
    Vector<int> b = {1, 0, 2};
    Vector<int> res(a.eqVectorProd(b));

    int tmp[3] = {4, 5, -2};

    int i = 0;
    for (auto elem : a)
        EXPECT_EQ(elem, tmp[i++]);

    i = 0;
    for (auto elem : res)
        EXPECT_EQ(elem, tmp[i++]);
}

TEST(binary, badVectorProd)
{
    Vector<int> a = {-3, 2, -1, 4};
    Vector<int> b = {1, 0, 2};
    Vector<int> c = {1, 0};

    EXPECT_ANY_THROW(a.vectorProd(b));
    EXPECT_ANY_THROW(b.vectorProd(a));
    EXPECT_ANY_THROW(a.eqVectorProd(b));
    EXPECT_ANY_THROW(b.eqVectorProd(a));

    EXPECT_ANY_THROW(a.vectorProd(c));
    EXPECT_ANY_THROW(c.vectorProd(a));
    EXPECT_ANY_THROW(a.eqVectorProd(c));
    EXPECT_ANY_THROW(c.eqVectorProd(a));
}

TEST(binary, collinear)
{
    Vector<int> a = {1, 2, 3};
    Vector<int> b = {-1, -2, -3};

    EXPECT_EQ(a.isCollinear(b), true);
}

TEST(binary, notCollinear)
{
    Vector<int> a = {1, 2, 3};
    Vector<int> b = {-1, -1, -1};

    EXPECT_EQ(a.isCollinear(b), false);
}

TEST(binary, zeroCollinear)
{
    Vector<int> a = {0, 0, 0};
    Vector<int> b = {-1, -1, -1};

    EXPECT_EQ(a.isCollinear(b), true);
    EXPECT_EQ(b.isCollinear(a), true);
}

TEST(binary, orthogonal)
{
    Vector<int> a = {1, 0, 0};
    Vector<int> b = {0, 0, 1};

    EXPECT_EQ(a.isOrthoganal(b), true);
}

TEST(binary, notOrthogonal)
{
    Vector<int> a = {1, 2, 3};
    Vector<int> b = {-1, -1, -1};

    EXPECT_EQ(a.isOrthoganal(b), false);
}

TEST(binary, zeroOrthogonal)
{
    Vector<int> a = {0, 0, 0};
    Vector<int> b = {-1, -1, -1};

    EXPECT_EQ(a.isCollinear(b), true);
    EXPECT_EQ(b.isCollinear(a), true);
}

#endif // TST_BINARY_HPP
