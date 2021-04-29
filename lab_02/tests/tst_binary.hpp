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

TEST(binary, byNumSum)
{
    Vector<int> a = {-100, 0, 6};
    int k = 10;

    Vector<int> res(a.byNumSum(k));

    int tmp_a[3] = {-100, 0, 6};
    int tmp[3] = {-90, 10, 16};

    int i = 0;
    for (auto elem : a)
        EXPECT_EQ(elem, tmp_a[i++]);

    i = 0;
    for (auto elem : res)
        EXPECT_EQ(elem, tmp[i++]);
}

TEST(binary, opByNumSum)
{
    Vector<int> a = {-100, 0, 6};
    int k = 10;

    Vector<int> res(a + k);

    int tmp_a[3] = {-100, 0, 6};
    int tmp[3] = {-90, 10, 16};

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

TEST(binary, eqByNumSum)
{
    Vector<int> a = {-100, 0, 6};
    int k = 10;

    Vector<int> res(a.eqByNumSum(k));

    int tmp[3] = {-90, 10, 16};

    int i = 0;
    for (auto elem : a)
        EXPECT_EQ(elem, tmp[i++]);

    i = 0;
    for (auto elem : res)
        EXPECT_EQ(elem, tmp[i++]);
}

TEST(binary, opEqByNumSum)
{
    Vector<int> a = {-100, 0, 6};
    int k = 10;

    Vector<int> res(a += k);

    int tmp[3] = {-90, 10, 16};

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

TEST(binary, byNumDiff)
{
    Vector<int> a = {-100, 0, 6};
    int k = 10;

    Vector<int> res(a.byNumDiff(k));

    int tmp_a[3] = {-100, 0, 6};
    int tmp[3] = {-110, -10, -4};

    int i = 0;
    for (auto elem : a)
        EXPECT_EQ(elem, tmp_a[i++]);

    i = 0;
    for (auto elem : res)
        EXPECT_EQ(elem, tmp[i++]);
}

TEST(binary, opByNumDiff)
{
    Vector<int> a = {-100, 0, 6};
    int k = 10;

    Vector<int> res(a - k);

    int tmp_a[3] = {-100, 0, 6};
    int tmp[3] = {-110, -10, -4};

    int i = 0;
    for (auto elem : a)
        EXPECT_EQ(elem, tmp_a[i++]);

    i = 0;
    for (auto elem : res)
        EXPECT_EQ(elem, tmp[i++]);
}


TEST(binary, badEqVecDiff)
{
    Vector<int> a = {-100, 0, 6};
    Vector<int> b = {200, 4};

    EXPECT_ANY_THROW(a.eqVecDiff(b));
}

TEST(binary, eqByNumDiff)
{
    Vector<int> a = {-100, 0, 6};
    int k = 10;

    Vector<int> res(a.eqByNumDiff(k));

    int tmp[3] = {-110, -10, -4};

    int i = 0;
    for (auto elem : a)
        EXPECT_EQ(elem, tmp[i++]);

    i = 0;
    for (auto elem : res)
        EXPECT_EQ(elem, tmp[i++]);
}

TEST(binary, opEqByNumDiff)
{
    Vector<int> a = {-100, 0, 6};
    int k = 10;

    Vector<int> res(a -= k);

    int tmp[3] = {-110, -10, -4};

    int i = 0;
    for (auto elem : a)
        EXPECT_EQ(elem, tmp[i++]);

    i = 0;
    for (auto elem : res)
        EXPECT_EQ(elem, tmp[i++]);
}

TEST(binary, vecProd)
{
    Vector<int> a = {-100, 0, 6};
    Vector<int> b = {200, 4, -5};

    Vector<int> res(a.vecProd(b));

    int tmp_a[3] = {-100, 0, 6};
    int tmp[3] = {-20000, 0, -30};

    int i = 0;
    for (auto elem : a)
        EXPECT_EQ(elem, tmp_a[i++]);

    i = 0;
    for (auto elem : res)
        EXPECT_EQ(elem, tmp[i++]);
}

TEST(binary, eqVecProd)
{
    Vector<int> a = {-100, 0, 6};
    Vector<int> b = {200, 4, -5};

    Vector<int> res(a.eqVecProd(b));

    int tmp[3] = {-20000, 0, -30};

    int i = 0;
    for (auto elem : a)
        EXPECT_EQ(elem, tmp[i++]);

    i = 0;
    for (auto elem : res)
        EXPECT_EQ(elem, tmp[i++]);
}

TEST(binary, opVecProd)
{
    Vector<int> a = {-100, 0, 6};
    Vector<int> b = {200, 4, -5};

    Vector<int> res(a * b);

    int tmp_a[3] = {-100, 0, 6};
    int tmp[3] = {-20000, 0, -30};

    int i = 0;
    for (auto elem : a)
        EXPECT_EQ(elem, tmp_a[i++]);

    i = 0;
    for (auto elem : res)
        EXPECT_EQ(elem, tmp[i++]);
}

TEST(binary, opEqVecProd)
{
    Vector<int> a = {-100, 0, 6};
    Vector<int> b = {200, 4, -5};

    Vector<int> res(a *= b);

    int tmp[3] = {-20000, 0, -30};

    int i = 0;
    for (auto elem : a)
        EXPECT_EQ(elem, tmp[i++]);

    i = 0;
    for (auto elem : res)
        EXPECT_EQ(elem, tmp[i++]);
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

TEST(binary, vecQuot)
{
    Vector<int> a = {-100, 0, 6};
    Vector<int> b = {-100, 1, 6};

    Vector<int> res(a.vecQuot(b));

    int tmp_a[3] = {-100, 0, 6};
    int tmp[3] = {1, 0, 1};

    int i = 0;
    for (auto elem : a)
        EXPECT_EQ(elem, tmp_a[i++]);

    i = 0;
    for (auto elem : res)
        EXPECT_EQ(elem, tmp[i++]);
}

TEST(binary, eqVecQuot)
{
    Vector<int> a = {-100, 0, 6};
    Vector<int> b = {-100, 1, 6};

    Vector<int> res(a.eqVecQuot(b));

    int tmp[3] = {1, 0, 1};

    int i = 0;
    for (auto elem : a)
        EXPECT_EQ(elem, tmp[i++]);

    i = 0;
    for (auto elem : res)
        EXPECT_EQ(elem, tmp[i++]);
}

TEST(binary, badVecQuot)
{
    Vector<int> a = {-100};
    Vector<int> b = {0};

    EXPECT_ANY_THROW(a.vecQuot(b));
}

TEST(binary, byNumQuot)
{
    Vector<int> a = {-100, 0, 6};
    int k = 10;

    Vector<int> res(a.byNumQuot(k));

    int tmp_a[3] = {-100, 0, 6};
    int tmp[3] = {-10, 0, 0};

    int i = 0;
    for (auto elem : a)
        EXPECT_EQ(elem, tmp_a[i++]);

    i = 0;
    for (auto elem : res)
        EXPECT_EQ(elem, tmp[i++]);
}

TEST(binary, opByNumQuot)
{
    Vector<int> a = {-100, 0, 6};
    int k = 10;

    Vector<int> res(a / k);

    int tmp_a[3] = {-100, 0, 6};
    int tmp[3] = {-10, 0, 0};

    int i = 0;
    for (auto elem : a)
        EXPECT_EQ(elem, tmp_a[i++]);

    i = 0;
    for (auto elem : res)
        EXPECT_EQ(elem, tmp[i++]);
}

TEST(binary, badEqVecQuot)
{
    Vector<int> a = {-100};
    Vector<int> b = {0};

    EXPECT_ANY_THROW(a.eqVecQuot(b));
}

TEST(binary, eqByNumQuot)
{
    Vector<int> a = {-100, 0, 6};
    int k = 10;

    Vector<int> res(a.eqByNumQuot(k));

    int tmp[3] = {-10, 0, 0};

    int i = 0;
    for (auto elem : a)
        EXPECT_EQ(elem, tmp[i++]);

    i = 0;
    for (auto elem : res)
        EXPECT_EQ(elem, tmp[i++]);
}

TEST(binary, opEqByNumQuot)
{
    Vector<int> a = {-100, 0, 6};
    int k = 10;

    Vector<int> res(a /= k);

    int tmp[3] = {-10, 0, 0};

    int i = 0;
    for (auto elem : a)
        EXPECT_EQ(elem, tmp[i++]);

    i = 0;
    for (auto elem : res)
        EXPECT_EQ(elem, tmp[i++]);
}

TEST(binary, opVecSum)
{
    Vector<int> a = {-100, 0, 6};
    Vector<int> b = {200, 4, -5};

    Vector<int> res(a + b);

    int tmp_a[3] = {-100, 0, 6};
    int tmp[3] = {100, 4, 1};

    int i = 0;
    for (auto elem : a)
        EXPECT_EQ(elem, tmp_a[i++]);

    i = 0;
    for (auto elem : res)
        EXPECT_EQ(elem, tmp[i++]);
}

TEST(binary, opEqVecSum)
{
    Vector<int> a = {-100, 0, 6};
    Vector<int> b = {200, 4, -5};

    Vector<int> res(a += b);

    int tmp[3] = {100, 4, 1};

    int i = 0;
    for (auto elem : a)
        EXPECT_EQ(elem, tmp[i++]);

    i = 0;
    for (auto elem : res)
        EXPECT_EQ(elem, tmp[i++]);
}

TEST(binary, opBadVecSum)
{
    Vector<int> a = {-100, 0, 6};
    Vector<int> b = {200, 4};

    EXPECT_ANY_THROW(a + b);
}

TEST(binary, opBadEqVecSum)
{
    Vector<int> a = {-100, 0, 6};
    Vector<int> b = {200, 4};

    EXPECT_ANY_THROW(a += b);
}

TEST(binary, opVecDiff)
{
    Vector<int> a = {-100, 0, 6};
    Vector<int> b = {200, 4, -5};

    Vector<int> res(a - b);

    int tmp_a[3] = {-100, 0, 6};
    int tmp[3] = {-300, -4, 11};

    int i = 0;
    for (auto elem : a)
        EXPECT_EQ(elem, tmp_a[i++]);

    i = 0;
    for (auto elem : res)
        EXPECT_EQ(elem, tmp[i++]);
}

TEST(binary, opEqVecDiff)
{
    Vector<int> a = {-100, 0, 6};
    Vector<int> b = {200, 4, -5};

    Vector<int> res(a -= b);

    int tmp[3] = {-300, -4, 11};

    int i = 0;
    for (auto elem : a)
        EXPECT_EQ(elem, tmp[i++]);

    i = 0;
    for (auto elem : res)
        EXPECT_EQ(elem, tmp[i++]);
}

TEST(binary, opBadVecDiff)
{
    Vector<int> a = {-100, 0, 6};
    Vector<int> b = {200, 4};

    EXPECT_ANY_THROW(a - b);
}

TEST(binary, opBadEqVecDiff)
{
    Vector<int> a = {-100, 0, 6};
    Vector<int> b = {200, 4};

    EXPECT_ANY_THROW(a -= b);
}

TEST(binary, opByNumProd)
{
    Vector<double> a = {5.1, -6, 0};
    Vector<double> res(a * -4);

    double tmp[3] = {-20.4, 24, 0};
    double tmpA[3] = {5.1, -6, 0};

    int i = 0;
    for (auto elem : a)
        EXPECT_NEAR(elem, tmpA[i++], EPS);

    i = 0;
    for (auto elem : res)
        EXPECT_NEAR(elem, tmp[i++], EPS);
}

TEST(binary, opEqByNumProd)
{
    Vector<double> a = {5.1, -6, 0};
    Vector<double> res(a *= -4);

    double tmp[3] = {-20.4, 24, 0};

    int i = 0;
    for (auto elem : a)
        EXPECT_NEAR(elem, tmp[i++], EPS);

    i = 0;
    for (auto elem : res)
        EXPECT_NEAR(elem, tmp[i++], EPS);
}

TEST(binary, opScalarProd)
{
    Vector<int> a = {3, 0, -7, 5, -1};
    Vector<int> b = {-3, 0, -7, 1, 8};

    EXPECT_EQ(a & b, 37);
}

TEST(binary, opVectorProd)
{
    Vector<int> a = {-3, 2, -1};
    Vector<int> b = {1, 0, 2};
    Vector<int> res(a ^ b);

    int tmp[3] = {4, 5, -2};
    int tmpA[3] = {-3, 2, -1};

    int i = 0;
    for (auto elem : a)
        EXPECT_EQ(elem, tmpA[i++]);

    i = 0;
    for (auto elem : res)
        EXPECT_EQ(elem, tmp[i++]);
}

TEST(binary, opEqVectorProd)
{
    Vector<int> a = {-3, 2, -1};
    Vector<int> b = {1, 0, 2};
    Vector<int> res(a ^= b);

    int tmp[3] = {4, 5, -2};

    int i = 0;
    for (auto elem : a)
        EXPECT_EQ(elem, tmp[i++]);

    i = 0;
    for (auto elem : res)
        EXPECT_EQ(elem, tmp[i++]);
}

TEST(binary, opBadVectorProd)
{
    Vector<int> a = {-3, 2, -1, 4};
    Vector<int> b = {1, 0, 2};
    Vector<int> c = {1, 0};

    EXPECT_ANY_THROW(a ^ b);
    EXPECT_ANY_THROW(b ^ a);
    EXPECT_ANY_THROW(a ^= b);
    EXPECT_ANY_THROW(b ^= a);

    EXPECT_ANY_THROW(a ^ c);
    EXPECT_ANY_THROW(c ^ a);
    EXPECT_ANY_THROW(a ^= c);
    EXPECT_ANY_THROW(c ^= a);
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

    EXPECT_EQ(a.isOrthogonal(b), true);
}

TEST(binary, notOrthogonal)
{
    Vector<int> a = {1, 2, 3};
    Vector<int> b = {-1, -1, -1};

    EXPECT_EQ(a.isOrthogonal(b), false);
}

TEST(binary, zeroOrthogonal)
{
    Vector<int> a = {0, 0, 0};
    Vector<int> b = {-1, -1, -1};

    EXPECT_EQ(a.isCollinear(b), true);
    EXPECT_EQ(b.isCollinear(a), true);
}

TEST(decltypetst, difVecSum)
{
    Vector<int> a = {-100, 0, 6};
    Vector<double> b = {0.5, -0.5, 0.};

    auto res(a.vecSum(b));

    int tmp_a[3] = {-100, 0, 6};
    double tmp[3] = {-99.5, -0.5, 6.};

    int i = 0;
    for (auto elem : a)
        EXPECT_EQ(elem, tmp_a[i++]);

    i = 0;
    for (auto elem : res)
        EXPECT_NEAR(elem, tmp[i++], EPS);
}

TEST(decltypetst, difOpVecSum)
{
    Vector<int> a = {-100, 0, 6};
    Vector<double> b = {0.5, -0.5, 0.};

    auto res(a + b);

    int tmp_a[3] = {-100, 0, 6};
    double tmp[3] = {-99.5, -0.5, 6.};

    int i = 0;
    for (auto elem : a)
        EXPECT_EQ(elem, tmp_a[i++]);

    i = 0;
    for (auto elem : res)
        EXPECT_NEAR(elem, tmp[i++], EPS);
}

TEST(decltypetst, difByNumSum)
{
    Vector<int> a = {-100, 0, 6};
    double k = 10;

    auto res(a.byNumSum(k));
    cout << typeid(res).name() << endl;

    int tmp_a[3] = {-100, 0, 6};
    double tmp[3] = {-90, 10, 16};

    int i = 0;
    for (auto elem : a)
        EXPECT_EQ(elem, tmp_a[i++]);

    i = 0;
    for (auto elem : res)
        EXPECT_NEAR(elem, tmp[i++], EPS);
}

TEST(decltypetst, difOpByNumSum)
{
    Vector<int> a = {-100, 0, 6};
    double k = 10;

    auto res(a + k);
    cout << typeid(res).name() << endl;

    int tmp_a[3] = {-100, 0, 6};
    double tmp[3] = {-90, 10, 16};

    int i = 0;
    for (auto elem : a)
        EXPECT_EQ(elem, tmp_a[i++]);

    i = 0;
    for (auto elem : res)
        EXPECT_NEAR(elem, tmp[i++], EPS);
}

TEST(decltypetst, difEqVecSum)
{
    Vector<int> a = {-100, 0, 6};
    Vector<double> b = {0.5, -0.5, 1.5};

    auto res(a.eqVecSum(b));

    int tmp[3] = {-99, 0, 7};

    int i = 0;
    for (auto elem : a)
        EXPECT_EQ(elem, tmp[i++]);

    i = 0;
    for (auto elem : res)
        EXPECT_EQ(elem, tmp[i++]);
}

TEST(decltypetst, difOpEqVecSum)
{
    Vector<int> a = {-100, 0, 6};
    Vector<double> b = {0.5, -0.5, 1.5};

    auto res(a += b);

    int tmp[3] = {-99, 0, 7};

    int i = 0;
    for (auto elem : a)
        EXPECT_EQ(elem, tmp[i++]);

    i = 0;
    for (auto elem : res)
        EXPECT_EQ(elem, tmp[i++]);
}

TEST(decltypetst, difEqByNumSum)
{
    Vector<int> a = {-100, 0, 6};
    double k = 0.5;

    auto res(a.eqByNumSum(k));

    int tmp[3] = {-99, 0, 6};

    int i = 0;
    for (auto elem : a)
        EXPECT_EQ(elem, tmp[i++]);

    i = 0;
    for (auto elem : res)
        EXPECT_EQ(elem, tmp[i++]);
}

TEST(decltypetst, difOpEqByNumSum)
{
    Vector<int> a = {-100, 0, 6};
    double k = 0.5;

    auto res(a += k);

    int tmp[3] = {-99, 0, 6};

    int i = 0;
    for (auto elem : a)
        EXPECT_EQ(elem, tmp[i++]);

    i = 0;
    for (auto elem : res)
        EXPECT_EQ(elem, tmp[i++]);
}

TEST(decltypetst, difVecDiff)
{
    Vector<int> a = {-100, 0, 6};
    Vector<double> b = {0.5, -0.5, 1.5};

    auto res(a - b);

    int tmpA[3] = {-100, 0, 6};
    double tmp[3] = {-100.5, 0.5, 4.5};

    int i = 0;
    for (auto elem : a)
        EXPECT_EQ(elem, tmpA[i++]);

    i = 0;
    for (auto elem : res)
        EXPECT_EQ(elem, tmp[i++]);
}

TEST(decltypetst, difByNumDiff)
{
    Vector<int> a = {-100, 0, 6};
    double k = 0.5;

    auto res(a - k);

    int tmpA[3] = {-100, 0, 6};
    double tmp[3] = {-100.5, -0.5, 5.5};

    int i = 0;
    for (auto elem : a)
        EXPECT_EQ(elem, tmpA[i++]);

    i = 0;
    for (auto elem : res)
        EXPECT_EQ(elem, tmp[i++]);
}

TEST(decltypetst, difEqVecDiff)
{
    Vector<int> a = {-100, 0, 6};
    Vector<double> b = {0.5, -0.5, 1.5};

    auto res(a -= b);

    int tmp[3] = {-100, 0, 4};

    int i = 0;
    for (auto elem : a)
        EXPECT_EQ(elem, tmp[i++]);

    i = 0;
    for (auto elem : res)
        EXPECT_EQ(elem, tmp[i++]);
}

TEST(decltypetst, difEqByNumDiff)
{
    Vector<int> a = {-100, 0, 6};
    double k = 0.5;

    auto res(a -= k);

    int tmp[3] = {-100, 0, 5};

    int i = 0;
    for (auto elem : a)
        EXPECT_EQ(elem, tmp[i++]);

    i = 0;
    for (auto elem : res)
        EXPECT_EQ(elem, tmp[i++]);
}

TEST(binary, difScalarProd)
{
    Vector<int> a = {3, 0, -7, 5, -1};
    Vector<double> b = {-3, 0, -7, 1, 8};

    EXPECT_NEAR(a & b, 37.0, EPS);
}

TEST(binary, difVectorProd)
{
    Vector<int> a = {-3, 2, -1};
    Vector<double> b = {1.5, 0, -2.4};
    auto res(b ^ a);

    double tmp[3] = {4.8, 8.7, 3};

    size_t i = 0;
    for (auto elem : res)
        EXPECT_EQ(elem, tmp[i++]);
}

TEST(binary, difEqVectorProd)
{
    Vector<int> a = {-3, 2, -1};
    Vector<double> b = {1.5, 0, -2.4};
    auto res(b ^= a);

    double tmp[3] = {4.8, 8.7, 3};

    int i = 0;
    for (auto elem : b)
        EXPECT_EQ(elem, tmp[i++]);

    i = 0;
    for (auto elem : res)
        EXPECT_EQ(elem, tmp[i++]);
}

TEST(binary, difCollinear)
{
    Vector<int> a = {1, 2, 3};
    Vector<double> b = {-1, -2, -3};

    EXPECT_EQ(a.isCollinear(b), true);
}

TEST(binary, difNotCollinear)
{
    Vector<double> a = {1, 2, 3};
    Vector<int> b = {-1, -1, -1};

    EXPECT_EQ(a.isCollinear(b), false);
}

TEST(binary, difOrthogonal)
{
    Vector<int> a = {1, 0, 0};
    Vector<double> b = {0, 0, 1};

    EXPECT_EQ(a.isOrthogonal(b), true);
}

TEST(binary, difNotOrthogonal)
{
    Vector<double> a = {1, 2, 3};
    Vector<int> b = {-1, -1, -1};

    EXPECT_EQ(a.isOrthogonal(b), false);
}

#endif // TST_BINARY_HPP
