#ifndef VECTOR_HPP
#define VECTOR_HPP

// debug
#include <iostream>
// debug

#include <cmath>
#include <limits>

#include "vector.h"
#include "exceptions.h"

#define EPS __DBL_EPSILON__

// BEGIN iterators
template <typename Type>
Iterator<Type> Vector<Type>::begin() noexcept
{
    return Iterator<Type>(*this);
}

template <typename Type>
Iterator<Type> Vector<Type>::end() noexcept
{
    return Iterator<Type>(*this) + size;
}

template <typename Type>
ConstIterator<Type> Vector<Type>::begin() const noexcept
{
    return ConstIterator<Type>(*this);
}

template <typename Type>
ConstIterator<Type> Vector<Type>::end() const noexcept
{
    return ConstIterator<Type>(*this) + size;
}

template <typename Type>
ConstIterator<Type> Vector<Type>::cbegin() const noexcept
{
    return ConstIterator<Type>(*this);
}

template <typename Type>
ConstIterator<Type> Vector<Type>::cend() const noexcept
{
    return ConstIterator<Type>(*this) + size;
}
// END interators


// BEGIN constructors
template <typename Type>
Vector<Type>::Vector(size_t sizeValue)
{
    allocate(sizeValue);
    size = sizeValue;
}

template <typename Type>
Vector<Type>::Vector(size_t sizeValue, const Type &filler)
{
    allocate(sizeValue);
    size = sizeValue;

    for (Iterator<Type> It = begin(); It != end(); ++It)
        *It = filler;
}

template <typename Type>
Vector<Type>::Vector(size_t sizeValue, const Type *arr)
{
    allocate(sizeValue);
    size = sizeValue;

    size_t i = 0;
    for (Iterator<Type> It = begin(); It != end(); ++It, ++i)
        *It = arr[i];
}


template <typename Type>
Vector<Type>::Vector(initializer_list<Type> elements)
{
    allocate(elements.size());
    size = elements.size();

    Iterator<Type> It = begin();

    for (auto elem : elements)
        *(It++) = elem;
}

template <typename Type>
Vector<Type>::Vector(const Vector<Type> &vector)
{
    allocate(vector.size);
    size = vector.size;

    ConstIterator<Type> src = vector.cbegin();
    Iterator<Type> dst = begin();

    for (; src != vector.cend(); ++src, ++dst)
        *dst = *src;
}

template <typename Type>
Vector<Type>::Vector(Vector<Type> &&vector) noexcept
{
    size = vector.size;
    data = vector.data;
    vector.data.reset();
}

template <typename Type>
template <typename ItType>
Vector<Type>::Vector(ItType begin, ItType end)
{
    size_t len = 0;
    for (auto it = begin; it != end; ++it, ++len);

    allocate(len);
    size = len;

    len = 0;
    for(auto it = begin; it != end; ++it, ++len)
        data[len] = *it;
}
// END constructors

// BEGIN assignment
template <typename Type>
Vector<Type> &Vector<Type>::operator=(initializer_list<Type> elements)
{
   allocate(elements.size());
   size = elements.size();

   Iterator<Type> it = begin();
   for (auto &cur : elements)
       *(it++) = cur;

   return *this;
}

template <typename Type>
Vector<Type> &Vector<Type>::operator=(const Vector<Type> &vector)
{
   allocate(vector.size);
   size = vector.size;

   Iterator<Type> it = begin();
   for (auto &cur : vector)
       *(it++) = cur;

   return *this;
}

template <typename Type>
Vector<Type> &Vector<Type>::operator=(Vector<Type> &&vector) noexcept
{
    allocate(vector.size);
    size = vector.size;
    data = vector.data;
    vector.data.reset();

    return *this;
}
// END assignment

// BEGIN comparison
template <typename Type>
bool Vector<Type>::operator==(const Vector<Type> &vector) const
{
    return isEqual(vector);
}

template <typename Type>
bool Vector<Type>::isEqual(const Vector<Type> &vector) const
{
    ConstIterator<Type> first = cbegin();
    ConstIterator<Type> second = vector.cbegin();

    bool areEqual = (size && size == vector.size);
    for (; areEqual && (first != cend()) && (second != vector.cend());
         ++first, ++second)
        areEqual = (*first == *second);

    return areEqual || !size;
}

template <typename Type>
bool Vector<Type>::operator!=(const Vector<Type> &vector) const
{
    return isNotEqual(vector);
}

template <typename Type>
bool Vector<Type>::isNotEqual(const Vector<Type> &vector) const
{
    return !(*this == vector);
}
// END comparison


// BEGIN methods and operators
template <typename Type>
template <typename OutType>
OutType Vector<Type>::length() const
{
    zeroSizeCheck(__LINE__);

    Type len = 0;
    for (ConstIterator<Type> It = cbegin(); It != cend(); ++It)
        len += *It * *It;

    return sqrt(len);
}

template <typename Type>
template <typename OutType>
Vector<OutType> Vector<Type>::getUnit() const
{
    zeroSizeCheck(__LINE__);
    Vector<OutType> res(size);

    OutType len = length<OutType>();
    Iterator<OutType> resIt = res.begin();

    ConstIterator<Type> srcIt = begin();
    for (; srcIt; ++srcIt, ++resIt)
    {
        *resIt = *srcIt / len;
        cout << *resIt << endl;
    }

    for (auto elem : res)
    {
    }

    return res;
}

template <typename Type>
Type & Vector<Type>::at(const size_t index)
{
    indexCheck(index, __LINE__);
    return data[index];
}

template <typename Type>
Type & Vector<Type>::operator[](const size_t index)
{
    return at(index);
}

template <typename Type>
const Type & Vector<Type>::at(const size_t index) const
{
    indexCheck(index, __LINE__);
    return data[index];
}

template <typename Type>
const Type & Vector<Type>::operator[](const size_t index) const
{
    return at(index);
}

template <typename Type>
Vector<Type> Vector<Type>::vecSum(const Vector<Type> &vector) const
{
    sizesCheck(vector, __LINE__);

    Vector<Type> res(*this);
    Iterator<Type> resIt = res.begin();
    ConstIterator<Type> vecIt = vector.cbegin();

    for (; resIt != res.end(); ++resIt)
        *resIt += *(vecIt++);

    return res;
}

template <typename Type>
Vector<Type> Vector<Type>::operator+(const Vector<Type> &vector) const
{
    return vecSum(vector);
}

template <typename Type>
template <typename Type2>
decltype(auto) Vector<Type>::vecSum(const Vector<Type2> &vector) const
{
    sizesCheck(vector, __LINE__);

    Vector<decltype(at(0) + vector.at(0))> res(size);
    ConstIterator<Type2> vecIt = vector.cbegin();

    size_t i = 0;
    for (; vecIt != vector.cend(); ++vecIt, ++i)
        res.at(i) = at(i) + *vecIt;

    return res;
}

template <typename Type>
template <typename Type2>
decltype(auto) Vector<Type>::operator+(const Vector<Type2> &vector) const
{
    return vecSum(vector);
}

template <typename Type>
Vector<Type> Vector<Type>::byNumSum(const Type &num) const
{
    Vector<Type> res(*this);
    Iterator<Type> resIt = res.begin();

    for (; resIt != res.end(); ++resIt)
        *resIt += num;

    return res;
}

template <typename Type>
Vector<Type> Vector<Type>::operator+(const Type &num) const
{
    return byNumSum(num);
}

template <typename Type>
template <typename Type2>
decltype(auto) Vector<Type>::byNumSum(const Type2 &num) const
{
    Vector<decltype(at(0) + num)> res(size);
    ConstIterator<Type> It = cbegin();

    for (size_t i = 0; It != cend(); ++It, ++i)
        res.at(i) = *It + num;

    return res;
}

template <typename Type>
template <typename Type2>
decltype(auto) Vector<Type>::operator+(const Type2 &num) const
{
    return byNumSum(num);
}

template <typename Type>
Vector<Type> &Vector<Type>::eqVecSum(const Vector<Type> &vector)
{
    sizesCheck(vector, __LINE__);

    Iterator<Type> resIt = begin();
    ConstIterator<Type> vecIt = vector.cbegin();

    for (; resIt != end(); ++resIt)
        *resIt += *(vecIt++);

    return *this;
}

template <typename Type>
Vector<Type> &Vector<Type>::operator+=(const Vector<Type> &vector)
{
    return eqVecSum(vector);
}

template <typename Type>
template <typename Type2>
Vector<Type> &Vector<Type>::eqVecSum(const Vector<Type2> &vector)
{
    sizesCheck(vector, __LINE__);

    Iterator<Type> resIt = begin();
    ConstIterator<Type2> vecIt = vector.cbegin();

    for (; resIt != end(); ++resIt)
        *resIt += *(vecIt++);

    return *this;
}

template <typename Type>
template <typename Type2>
Vector<Type> &Vector<Type>::operator+=(const Vector<Type2> &vector)
{
    return eqVecSum(vector);
}

template <typename Type>
Vector<Type> &Vector<Type>::eqByNumSum(const Type &num)
{
    Iterator<Type> resIt = begin();

    for (; resIt != end(); ++resIt)
        *resIt += num;

    return *this;
}

template <typename Type>
Vector<Type> &Vector<Type>::operator+=(const Type &num)
{
    return eqByNumSum(num);
}

template <typename Type>
template <typename Type2>
Vector<Type> &Vector<Type>::eqByNumSum(const Type2 &num)
{
    Iterator<Type> resIt = begin();

    for (; resIt != end(); ++resIt)
        *resIt += num;

    return *this;
}

template <typename Type>
template <typename Type2>
Vector<Type> &Vector<Type>::operator+=(const Type2 &num)
{
    return eqByNumSum(num);
}

template <typename Type>
Vector<Type> Vector<Type>::vecDiff(const Vector<Type> &vector) const
{
    sizesCheck(vector, __LINE__);

    Vector<Type> res(*this);
    Iterator<Type> resIt = res.begin();
    ConstIterator<Type> vecIt = vector.cbegin();

    for (; resIt != res.end(); ++resIt)
        *resIt -= *(vecIt++);

    return res;
}

template <typename Type>
Vector<Type> Vector<Type>::operator-(const Vector<Type> &vector) const
{
    return vecDiff(vector);
}

template <typename Type>
template <typename Type2>
decltype(auto) Vector<Type>::vecDiff(const Vector<Type2> &vector) const
{
    sizesCheck(vector, __LINE__);

    Vector<decltype(at(0) - vector.at(0))> res(size);
    ConstIterator<Type2> vecIt = vector.cbegin();

    size_t i = 0;
    for (; vecIt != vector.cend(); ++vecIt, ++i)
        res.at(i) = at(i) - *vecIt;

    return res;
}

template <typename Type>
template <typename Type2>
decltype(auto) Vector<Type>::operator-(const Vector<Type2> &vector) const
{
    return vecDiff(vector);
}

template <typename Type>
Vector<Type> Vector<Type>::byNumDiff(const Type &num) const
{
    Vector<Type> res(*this);
    Iterator<Type> resIt = res.begin();

    for (; resIt != res.end(); ++resIt)
        *resIt -= num;

    return res;
}

template <typename Type>
Vector<Type> Vector<Type>::operator-(const Type &num) const
{
    return byNumDiff(num);
}

template <typename Type>
template <typename Type2>
decltype(auto) Vector<Type>::byNumDiff(const Type2 &num) const
{
    Vector<decltype(at(0) - num)> res(size);
    ConstIterator<Type> It = cbegin();

    for (size_t i = 0; It != cend(); ++It, ++i)
        res.at(i) = *It - num;

    return res;
}

template <typename Type>
template <typename Type2>
decltype(auto) Vector<Type>::operator-(const Type2 &num) const
{
    return byNumDiff(num);
}

template <typename Type>
Vector<Type> &Vector<Type>::eqVecDiff(const Vector<Type> &vector)
{
    sizesCheck(vector, __LINE__);

    Iterator<Type> resIt = begin();
    ConstIterator<Type> vecIt = vector.cbegin();

    for (; resIt != end(); ++resIt)
        *resIt -= *(vecIt++);

    return *this;
}

template <typename Type>
Vector<Type> &Vector<Type>::operator-=(const Vector<Type> &vector)
{
    return eqVecDiff(vector);
}

template <typename Type>
template <typename Type2>
Vector<Type> &Vector<Type>::eqVecDiff(const Vector<Type2> &vector)
{
    sizesCheck(vector, __LINE__);

    Iterator<Type> resIt = begin();
    ConstIterator<Type2> vecIt = vector.cbegin();

    for (; resIt != end(); ++resIt)
        *resIt -= *(vecIt++);

    return *this;
}

template <typename Type>
template <typename Type2>
Vector<Type> &Vector<Type>::operator-=(const Vector<Type2> &vector)
{
    return eqVecDiff(vector);
}


template <typename Type>
Vector<Type> &Vector<Type>::eqByNumDiff(const Type &num)
{
    Iterator<Type> resIt = begin();

    for (; resIt != end(); ++resIt)
        *resIt -= num;

    return *this;
}

template <typename Type>
Vector<Type> &Vector<Type>::operator-=(const Type &num)
{
    return eqByNumDiff(num);
}

template <typename Type>
template <typename Type2>
Vector<Type> &Vector<Type>::eqByNumDiff(const Type2 &num)
{
    Iterator<Type> resIt = begin();

    for (; resIt != end(); ++resIt)
        *resIt -= num;

    return *this;
}

template <typename Type>
template <typename Type2>
Vector<Type> &Vector<Type>::operator-=(const Type2 &num)
{
    return eqByNumDiff(num);
}


template <typename Type>
Vector<Type> Vector<Type>::neg() const
{
    Vector<Type> res(*this);

    for (auto &elem : res)
        elem = -elem;

    return res;
}

template <typename Type>
Vector<Type> Vector<Type>::operator-() const
{
    return neg();
}

template <typename Type>
Vector<Type> Vector<Type>::vecProd(const Vector<Type> &vector) const
{
    sizesCheck(vector, __LINE__);

    Vector<Type> res(*this);
    Iterator<Type> resIt = res.begin();
    ConstIterator<Type> vecIt = vector.cbegin();

    for (; resIt != res.end(); ++resIt)
        *resIt *= *(vecIt++);

    return res;
}

template <typename Type>
Vector<Type> Vector<Type>::operator*(const Vector<Type> &vector) const
{
    return vecProd(vector);
}

template <typename Type>
template <typename Type2>
decltype(auto) Vector<Type>::vecProd(const Vector<Type2> &vector) const
{
    sizesCheck(vector, __LINE__);

    Vector<decltype(at(0) - vector.at(0))> res(size);
    ConstIterator<Type2> vecIt = vector.cbegin();

    size_t i = 0;
    for (; vecIt != vector.cend(); ++vecIt, ++i)
        res.at(i) = at(i) * *vecIt;

    return res;
}

template <typename Type>
template <typename Type2>
decltype(auto) Vector<Type>::operator*(const Vector<Type2> &vector) const
{
    return vecProd(vector);
}


template <typename Type>
Vector<Type> Vector<Type>::byNumProd(const Type &num) const
{
    Vector<Type> res(*this);
    Iterator<Type> resIt = res.begin();

    for (; resIt != res.end(); ++resIt)
        *resIt *= num;

    return res;
}

template <typename Type>
Vector<Type> Vector<Type>::operator*(const Type &num) const
{
    return byNumProd(num);
}

template <typename Type>
template <typename Type2>
decltype(auto) Vector<Type>::byNumProd(const Type2 &num) const
{
    Vector<decltype(at(0) - num)> res(size);
    ConstIterator<Type> It = cbegin();

    for (size_t i = 0; It != cend(); ++It, ++i)
        res.at(i) = *It * num;

    return res;
}

template <typename Type>
template <typename Type2>
decltype(auto) Vector<Type>::operator*(const Type2 &num) const
{
    return byNumProd(num);
}

template <typename Type>
Vector<Type> &Vector<Type>::eqVecProd(const Vector<Type> &vector)
{
    sizesCheck(vector, __LINE__);

    Iterator<Type> resIt = begin();
    ConstIterator<Type> vecIt = vector.cbegin();

    for (; resIt != end(); ++resIt)
        *resIt *= *(vecIt++);

    return *this;
}

template <typename Type>
Vector<Type> &Vector<Type>::operator*=(const Vector<Type> &vector)
{
    return eqVecProd(vector);
}

template <typename Type>
template <typename Type2>
Vector<Type> &Vector<Type>::eqVecProd(const Vector<Type2> &vector)
{
    sizesCheck(vector, __LINE__);

    Iterator<Type> resIt = begin();
    ConstIterator<Type2> vecIt = vector.cbegin();

    for (; resIt != end(); ++resIt)
        *resIt *= *(vecIt++);

    return *this;
}

template <typename Type>
template <typename Type2>
Vector<Type> &Vector<Type>::operator*=(const Vector<Type2> &vector)
{
    return eqVecProd(vector);
}

template <typename Type>
Vector<Type> &Vector<Type>::eqByNumProd(const Type &num)
{
    Iterator<Type> resIt = begin();

    for (; resIt != end(); ++resIt)
        *resIt *= num;

    return *this;
}

template <typename Type>
Vector<Type> &Vector<Type>::operator*=(const Type &num)
{
    return eqByNumProd(num);
}

template <typename Type>
template <typename Type2>
Vector<Type> &Vector<Type>::eqByNumProd(const Type2 &num)
{
    Iterator<Type> resIt = begin();

    for (; resIt != end(); ++resIt)
        *resIt *= num;

    return *this;
}

template <typename Type>
template <typename Type2>
Vector<Type> &Vector<Type>::operator*=(const Type2 &num)
{
    return eqByNumProd(num);
}

template <typename Type>
Vector<Type> Vector<Type>::vecQuot(const Vector<Type> &vector) const
{
    sizesCheck(vector, __LINE__);

    Vector<Type> res(*this);
    Iterator<Type> resIt = res.begin();
    ConstIterator<Type> vecIt = vector.cbegin();

    for (; resIt != res.end(); ++resIt)
    {
        divisionByZeroCheck(*vecIt, __LINE__);
        *resIt /= *(vecIt++);
    }

    return res;
}

template <typename Type>
Vector<Type> Vector<Type>::operator/(const Vector<Type> &vector) const
{
    return vecQuot(vector);
}

template <typename Type>
template <typename Type2>
decltype(auto) Vector<Type>::vecQuot(const Vector<Type2> &vector) const
{
    sizesCheck(vector, __LINE__);

    Vector<decltype(at(0) - vector.at(0))> res(size);
    ConstIterator<Type2> vecIt = vector.cbegin();

    size_t i = 0;
    for (; vecIt != vector.cend(); ++vecIt, ++i)
    {
        divisionByZeroCheck(*vecIt, __LINE__);
        res.at(i) = at(i) / *vecIt;
    }

    return res;
}

template <typename Type>
template <typename Type2>
decltype(auto) Vector<Type>::operator/(const Vector<Type2> &vector) const
{
    return vecQuot(vector);
}

template <typename Type>
Vector<Type> Vector<Type>::byNumQuot(const Type &num) const
{
    divisionByZeroCheck(num, __LINE__);

    Vector<Type> res(*this);
    Iterator<Type> resIt = res.begin();

    for (; resIt != res.end(); ++resIt)
        *resIt /= num;

    return res;
}

template <typename Type>
Vector<Type> Vector<Type>::operator/(const Type &num) const
{
    return byNumQuot(num);
}

template <typename Type>
template <typename Type2>
decltype(auto) Vector<Type>::byNumQuot(const Type2 &num) const
{
    divisionByZeroCheck(num, __LINE__);

    Vector<decltype(at(0) - num)> res(size);
    ConstIterator<Type> It = cbegin();

    for (size_t i = 0; It != cend(); ++It, ++i)
        res.at(i) = *It / num;

    return res;
}

template <typename Type>
template <typename Type2>
decltype(auto) Vector<Type>::operator/(const Type2 &num) const
{
    return byNumQuot(num);
}

template <typename Type>
Vector<Type> &Vector<Type>::eqVecQuot(const Vector<Type> &vector)
{
    sizesCheck(vector, __LINE__);

    Iterator<Type> resIt = begin();
    ConstIterator<Type> vecIt = vector.cbegin();

    for (; resIt != end(); ++resIt)
    {
        divisionByZeroCheck(*vecIt, __LINE__);
        *resIt /= *(vecIt++);
    }

    return *this;
}

template <typename Type>
Vector<Type> &Vector<Type>::operator/=(const Vector<Type> &vector)
{
    return eqVecQuot(vector);
}

template <typename Type>
template <typename Type2>
Vector<Type> &Vector<Type>::eqVecQuot(const Vector<Type2> &vector)
{
    sizesCheck(vector, __LINE__);

    Iterator<Type> resIt = begin();
    ConstIterator<Type2> vecIt = vector.cbegin();

    for (; resIt != end(); ++resIt)
    {
        divisionByZeroCheck(*vecIt, __LINE__);
        *resIt /= *(vecIt++);
    }

    return *this;
}

template <typename Type>
template <typename Type2>
Vector<Type> &Vector<Type>::operator/=(const Vector<Type2> &vector)
{
    return eqVecQuot(vector);
}

template <typename Type>
Vector<Type> &Vector<Type>::eqByNumQuot(const Type &num)
{
    divisionByZeroCheck(num, __LINE__);

    Iterator<Type> resIt = begin();

    for (; resIt != end(); ++resIt)
        *resIt /= num;

    return *this;
}

template <typename Type>
Vector<Type> &Vector<Type>::operator/=(const Type &num)
{
    return eqByNumQuot(num);
}

template <typename Type>
template <typename Type2>
Vector<Type> &Vector<Type>::eqByNumQuot(const Type2 &num)
{
    divisionByZeroCheck(num, __LINE__);

    Iterator<Type> resIt = begin();

    for (; resIt != end(); ++resIt)
        *resIt /= num;

    return *this;
}

template <typename Type>
template <typename Type2>
Vector<Type> &Vector<Type>::operator/=(const Type2 &num)
{
    return eqByNumQuot(num);
}

template <typename Type>
Type Vector<Type>::scalarProd(const Vector<Type> &vector) const
{
    sizesCheck(vector, __LINE__);

    ConstIterator<Type> it1 = cbegin();
    ConstIterator<Type> it2 = vector.cbegin();

    Type sum = 0;
    for (; it1 != end(); ++it1, ++it2)
        sum += *it1 * *it2;

    return sum;
}

template <typename Type>
Type Vector<Type>::operator&(const Vector<Type> &vector) const
{
    return scalarProd(vector);
}

template <typename Type>
template <typename Type2>
decltype(auto) Vector<Type>::scalarProd(const Vector<Type2> &vector) const
{
    sizesCheck(vector, __LINE__);

    ConstIterator<Type> it1 = cbegin();
    ConstIterator<Type2> it2 = vector.cbegin();

    decltype(*it1 * *it2) sum = 0;
    for (; it1 != end(); ++it1, ++it2)
        sum += *it1 * *it2;

    return sum;
}

template <typename Type>
template <typename Type2>
decltype(auto) Vector<Type>::operator&(const Vector<Type2> &vector) const
{
    return scalarProd(vector);
}

template <typename Type>
Vector<Type> Vector<Type>::vectorProd(const Vector<Type> &vector) const
{
    vectorProdSizesCheck(vector, __LINE__);

    Vector<Type> res(size);

    res.at(0) = at(1) * vector.at(2) - at(2) * vector.at(1);
    res.at(1) = at(2) * vector.at(0) - at(0) * vector.at(2);
    res.at(2) = at(0) * vector.at(1) - at(1) * vector.at(0);

    return res;
}

template <typename Type>
Vector<Type> Vector<Type>::operator^(const Vector<Type> &vector) const
{
    return vectorProd(vector);
}

template <typename Type>
template <typename Type2>
decltype(auto) Vector<Type>::vectorProd(const Vector<Type2> &vector) const
{
    vectorProdSizesCheck(vector, __LINE__);

    Vector<decltype(at(0) * vector.at(0))> res(size);

    res.at(0) = at(1) * vector.at(2) - at(2) * vector.at(1);
    res.at(1) = at(2) * vector.at(0) - at(0) * vector.at(2);
    res.at(2) = at(0) * vector.at(1) - at(1) * vector.at(0);

    return res;
}

template <typename Type>
template <typename Type2>
decltype(auto) Vector<Type>::operator^(const Vector<Type2> &vector) const
{
    return vectorProd(vector);
}

template <typename Type>
Vector<Type> &Vector<Type>::eqVectorProd(const Vector<Type> &vector)
{
    vectorProdSizesCheck(vector, __LINE__);

    Vector<Type> tmp(*this);

    at(0) = tmp.at(1) * vector.at(2) - tmp.at(2) * vector.at(1);
    at(1) = tmp.at(2) * vector.at(0) - tmp.at(0) * vector.at(2);
    at(2) = tmp.at(0) * vector.at(1) - tmp.at(1) * vector.at(0);

    return *this;
}

template <typename Type>
Vector<Type> &Vector<Type>::operator^=(const Vector<Type> &vector)
{
    return eqVectorProd(vector);
}

template <typename Type>
template <typename Type2>
Vector<Type> &Vector<Type>::eqVectorProd(const Vector<Type2> &vector)
{
    vectorProdSizesCheck(vector, __LINE__);

    Vector<Type> tmp(*this);

    at(0) = tmp.at(1) * vector.at(2) - tmp.at(2) * vector.at(1);
    at(1) = tmp.at(2) * vector.at(0) - tmp.at(0) * vector.at(2);
    at(2) = tmp.at(0) * vector.at(1) - tmp.at(1) * vector.at(0);

    return *this;
}

template <typename Type>
template <typename Type2>
Vector<Type> &Vector<Type>::operator^=(const Vector<Type2> &vector)
{
    return eqVectorProd(vector);
}

template <typename Type>
double Vector<Type>::angle(const Vector<Type> &vector) const
{
    double res = 0;

    if (!(abs(length<double>()) < EPS || abs(vector.length<double>()) < EPS))
        res = acos(scalarProd(vector) / (length<double>() * vector.length<double>()));

    return res;
}

template <typename Type>
template <typename Type2>
double Vector<Type>::angle(const Vector<Type2> &vector) const
{
    double res = 0;

    if (!(abs(this->template length<double>()) < EPS ||
          abs(vector.template length<double>()) < EPS))
        res = acos(scalarProd(vector) /
                   (this->template length<double>() *
                    vector.template length<double>()));

    return res;
}

template <typename Type>
bool Vector<Type>::isCollinear(const Vector<Type> &vector) const
{
    sizesCheck(vector, __LINE__);

    double ang = angle(vector);
    return abs(ang) < EPS || abs(ang - M_PI) < EPS;
}

template <typename Type>
template <typename Type2>
bool Vector<Type>::isCollinear(const Vector<Type2> &vector) const
{
    sizesCheck(vector, __LINE__);

    double ang = angle(vector);
    return abs(ang) < EPS || abs(ang - M_PI) < EPS;
}

template <typename Type>
bool Vector<Type>::isOrthogonal(const Vector<Type> &vector) const
{
    sizesCheck(vector, __LINE__);

    return abs(angle(vector) - M_PI / 2) < EPS;
}

template <typename Type>
template <typename Type2>
bool Vector<Type>::isOrthogonal(const Vector<Type2> &vector) const
{
    sizesCheck(vector, __LINE__);

    return abs(angle(vector) - M_PI / 2) < EPS;
}

template <typename Type>
bool Vector<Type>::isZero() const
{
    return abs(length<double>()) < EPS;
}


// BEGIN allocate
template <typename Type>
void Vector<Type>::allocate(size_t sizeValue)
{
    time_t curTime = time(NULL);
    uint line;
    try
    {
        line = __LINE__;
        data.reset(new Type[sizeValue]);
    }
    catch (bad_alloc &err)
    {
        throw MemoryException(ctime(&curTime), __FILE__, line,
                              typeid(*this).name(), __FUNCTION__);
    }
}
// END allocate


// BEGIN checks
template <typename Type>
void Vector<Type>::zeroSizeCheck(const uint line) const
{
    if (isEmpty())
    {
        time_t curTime = time(NULL);
        throw EmptyVectorException(ctime(&curTime), __FILE__,
                                  line, typeid(*this).name(),
                                  __FUNCTION__);
    }
}

template <typename Type>
void Vector<Type>::indexCheck(const size_t index, const uint line) const
{
    if (index >= getSize())
    {
        time_t curTime = time(NULL);
        throw OutOfRangeException(ctime(&curTime), __FILE__,
                                  line, typeid(*this).name(),
                                  __FUNCTION__);
    }
}

template <typename Type>
template <typename Type2>
void Vector<Type>::sizesCheck(const Vector<Type2> &vector,
                              const uint line) const
{
    if (getSize() != vector.getSize())
    {
        time_t curTime = time(NULL);
        throw NotEqualSizesException(ctime(&curTime), __FILE__,
                                  line, typeid(*this).name(),
                                  __FUNCTION__);
    }
}

template <typename Type>
template <typename Type2>
void Vector<Type>::vectorProdSizesCheck(const Vector<Type2> &vector,
                              const uint line) const
{
    if (getSize() != 3 || vector.getSize() != 3)
    {
        time_t curTime = time(NULL);
        throw Not3DException(ctime(&curTime), __FILE__,
                                  line, typeid(*this).name(),
                                  __FUNCTION__);
    }
}

template <typename Type>
template <typename Type2>
void Vector<Type>::divisionByZeroCheck(const Type2 &num,
                              const uint line) const
{
    if (abs(num) < EPS)
    {
        time_t curTime = time(NULL);
        throw DivisionByZeroException(ctime(&curTime), __FILE__,
                                  line, typeid(*this).name(),
                                  __FUNCTION__);
    }
}
// END checks

#endif
