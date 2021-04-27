#ifndef VECTOR_HPP
#define VECTOR_HPP

//debug
#include <iostream>
//debug

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

template <typename Type>
template <typename OutType>
OutType Vector<Type>::length() const
{
    // ошибка пустого вектора

    Type len = 0;
    for (ConstIterator<Type> It = cbegin(); It != cend(); ++It)
        len += *It * *It;

    return sqrt(len);
}

// BEGIN methods and operators
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
Vector<Type> Vector<Type>::neg() const
{
    Vector<Type> res(*this);

    for (auto &elem : res)
        elem = -elem;

    return res;
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
