#ifndef VECTOR_HPP
#define VECTOR_HPP

//debug
#include <iostream>
//debug

#include <cmath>

#include "vector.h"
#include "exceptions.h"

#define EPS 1e-6

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
    return Iterator<Type>(*this);
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
    // Нужно ли обнулять
    // Если произошла ошибка, размер изменится
    size = sizeValue;
    allocate(size);
}

template <typename Type>
Vector<Type>::Vector(size_t sizeValue, Type filler)
{
    size = sizeValue;
    allocate(size);

    for (Iterator<Type> It = begin(); It != end(); ++It)
        *It = filler;
}

template <typename Type>
Vector<Type>::Vector(const initializer_list<Type> &elements)
{
    size = elements.size();
    allocate(size);

    Iterator<Type> It = begin();

    for (auto elem : elements)
        *(It++) = elem;
}

template <typename Type>
Vector<Type>::Vector(const Vector<Type> &vector)
{
    data = shared_ptr<Type[]>(new Type[vector.size]);

    if (!data)
    {
        time_t curTime = time(NULL);
        throw MemoryException(ctime(&curTime), __FILE__,
                              __LINE__, typeid(*this).name(),
                              __FUNCTION__);
    }

    size = vector.size;

    ConstIterator<Type> src = vector.cbegin();
    Iterator<Type> dst = begin();

    for (; src != vector.cend(); ++src, ++dst)
        *dst = *src;
}
// END constructors


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

    bool areEqual = true;
    for (; areEqual && (first != cend()) && (second != vector.cend());
         ++first, ++second)
        areEqual = (*first == *second);

    return areEqual;
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
double Vector<Type>::length() const
{
    if (!size)
    {
        // другая ошибка
        time_t curTime = time(NULL);
        throw OutOfRangeException(ctime(&curTime), __FILE__,
                                  __LINE__, typeid(*this).name(),
                                  __FUNCTION__);
    }

    Type len = 0;
    for (ConstIterator<Type> It = cbegin(); It != cend(); ++It)
        len += *It * *It;

    return sqrt(len);
}

template <typename Type>
Type & Vector<Type>::at(const size_t index)
{
    // Вынести в метод
    if (index >= size)
    {
        time_t curTime = time(NULL);
        throw OutOfRangeException(ctime(&curTime), __FILE__,
                                  __LINE__, typeid(*this).name(),
                                  __FUNCTION__);
    }

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
    if (index >= size)
    {
        time_t curTime = time(NULL);
        throw OutOfRangeException(ctime(&curTime), __FILE__,
                                  __LINE__, typeid(*this).name(),
                                  __FUNCTION__);
    }

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
    if (size != vector.size)
    {
        // изменить exception
        time_t curTime = time(NULL);
        throw OutOfRangeException(ctime(&curTime), __FILE__,
                                  __LINE__, typeid(*this).name(),
                                  __FUNCTION__);
    }

    // проверить на auto
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
Vector<Type> Vector<Type>::eqVecSum(const Vector<Type> &vector)
{
    if (size != vector.size)
    {
        // изменить exception
        time_t curTime = time(NULL);
        throw OutOfRangeException(ctime(&curTime), __FILE__,
                                  __LINE__, typeid(*this).name(),
                                  __FUNCTION__);
    }

    Iterator<Type> resIt = begin();
    ConstIterator<Type> vecIt = vector.cbegin();

    for (; resIt != end(); ++resIt)
        *resIt += *(vecIt++);

    return *this;
}

template <typename Type>
Vector<Type> Vector<Type>::operator+=(const Vector<Type> &vector)
{
    return eqVecSum(vector);
}

template <typename Type>
Vector<Type> Vector<Type>::vecDiff(const Vector<Type> &vector) const
{
    if (size != vector.size)
    {
        // изменить exception
        time_t curTime = time(NULL);
        throw OutOfRangeException(ctime(&curTime), __FILE__,
                                  __LINE__, typeid(*this).name(),
                                  __FUNCTION__);
    }

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
Vector<Type> Vector<Type>::eqVecDiff(const Vector<Type> &vector)
{
    if (size != vector.size)
    {
        // изменить exception
        time_t curTime = time(NULL);
        throw OutOfRangeException(ctime(&curTime), __FILE__,
                                  __LINE__, typeid(*this).name(),
                                  __FUNCTION__);
    }

    Iterator<Type> resIt = begin();
    ConstIterator<Type> vecIt = vector.cbegin();

    for (; resIt != end(); ++resIt)
        *resIt -= *(vecIt++);

    return *this;
}

template <typename Type>
Vector<Type> Vector<Type>::operator-=(const Vector<Type> &vector)
{
    return eqVecDiff(vector);
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
Vector<Type> Vector<Type>::eqByNumProd(const Type &num)
{
    Iterator<Type> resIt = begin();

    for (; resIt != end(); ++resIt)
        *resIt *= num;

    return *this;
}

template <typename Type>
Vector<Type> Vector<Type>::operator*=(const Type &num)
{
    return eqByNumProd(num);
}

template <typename Type>
Type Vector<Type>::scalarProd(const Vector<Type> &vector) const
{
    if (size != vector.size)
    {
        // изменить exception
        time_t curTime = time(NULL);
        throw OutOfRangeException(ctime(&curTime), __FILE__,
                                  __LINE__, typeid(*this).name(),
                                  __FUNCTION__);
    }

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
Vector<Type> Vector<Type>::vectorProd(const Vector<Type> &vector) const
{
    if (size != 3 || vector.size != 3)
    {
        // изменить exception
        time_t curTime = time(NULL);
        throw OutOfRangeException(ctime(&curTime), __FILE__,
                                  __LINE__, typeid(*this).name(),
                                  __FUNCTION__);
    }

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
Vector<Type> Vector<Type>::eqVectorProd(const Vector<Type> &vector)
{
    if (size != 3 || vector.size != 3)
    {
        // изменить exception
        time_t curTime = time(NULL);
        throw OutOfRangeException(ctime(&curTime), __FILE__,
                                  __LINE__, typeid(*this).name(),
                                  __FUNCTION__);
    }

    Vector<Type> tmp(*this);

    at(0) = tmp.at(1) * vector.at(2) - tmp.at(2) * vector.at(1);
    at(1) = tmp.at(2) * vector.at(0) - tmp.at(0) * vector.at(2);
    at(2) = tmp.at(0) * vector.at(1) - tmp.at(1) * vector.at(0);

    return *this;
}

template <typename Type>
Vector<Type> Vector<Type>::operator^=(const Vector<Type> &vector)
{
    return eqVectorProd(vector);
}

template <typename Type>
double Vector<Type>::angle(const Vector<Type> &vector) const
{
    double res = 0;

    if (!(abs(length()) < EPS || abs(vector.length()) < EPS))
        res = acos(scalarProd(vector) / (length() * vector.length()));

    return res;
}

template <typename Type>
bool Vector<Type>::isCollinear(const Vector<Type> &vector) const
{
    if (size != vector.size)
    {
        // изменить
        time_t curTime = time(NULL);
        throw OutOfRangeException(ctime(&curTime), __FILE__,
                                  __LINE__, typeid(*this).name(),
                                  __FUNCTION__);
    }

    double ang = angle(vector);
    return abs(ang) < EPS || abs(ang - M_PI) < EPS;
}

template <typename Type>
bool Vector<Type>::isOrthoganal(const Vector<Type> &vector) const
{
    if (size != vector.size)
    {
        // изменить
        time_t curTime = time(NULL);
        throw OutOfRangeException(ctime(&curTime), __FILE__,
                                  __LINE__, typeid(*this).name(),
                                  __FUNCTION__);
    }

    return abs(angle(vector) - M_PI / 2) < EPS;
}


template <typename Type>
bool Vector<Type>::isZero() const
{
    return abs(length()) < EPS;
}


// BEGIN allocate
template <typename Type>
void Vector<Type>::allocate(size_t sizeValue)
{
    try
    {
        time_t curTime = time(NULL);
        uint line = __LINE__;
        Type * tmp = new Type[sizeValue];

        if (!tmp)
            throw MemoryException(ctime(&curTime), __FILE__, line,
                                  typeid(*this).name(), __FUNCTION__);

        data.reset(tmp);
    }
    catch (MemoryException &err)
    {
        cout << err.what() << endl;
    }
}
// END allocate

#endif
