#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <time.h>
#include "iterator.h"
#include "exceptions.h"

template <typename Type>
Iterator<Type>::Iterator(const Vector<Type> &vector) noexcept
{
    ptr = vector.data;
    size = vector.size;
    index = 0;
}

template <typename Type>
Type &Iterator<Type>::operator*()
{
    exprideCheck(__LINE__);
    indexCheck(__LINE__);

    return ptr.lock()[index];
}

template <typename Type>
const Type &Iterator<Type>::operator*() const
{
    exprideCheck(__LINE__);
    indexCheck(__LINE__);

    // Возможно, здесь нужна локальная переменная
    return ptr.lock()[index];
}

template <typename Type>
Type *Iterator<Type>::operator->()
{
    exprideCheck(__LINE__);
    indexCheck(__LINE__);

    return ptr.lock() + index;
}

template <typename Type>
const Type *Iterator<Type>::operator->() const
{
    exprideCheck(__LINE__);
    indexCheck(__LINE__);

    return ptr.lock() + index;
}

template <typename Type>
Iterator<Type> & Iterator<Type>::operator++() noexcept
{
    ++index;
    return *this;
}

template <typename Type>
Iterator<Type> Iterator<Type>::operator++(int) noexcept
{
    Iterator<Type> tmp(*this);
    ++(*this);
    return tmp;
}

template <typename Type>
Iterator<Type> Iterator<Type>::operator+(const size_t dif) const
{
    // Ошибки?
    Iterator<Type> tmp(*this);
    tmp.index += dif;
    return tmp;
}

template <typename Type>
bool Iterator<Type>::operator==(const Iterator<Type> &iterator) const
{
    return ptr.lock() == iterator.ptr.lock() && index == iterator.index;
}

template <typename Type>
bool Iterator<Type>::operator!=(const Iterator<Type> &iterator) const
{
    return !(*this == iterator);
}

template <typename Type>
void Iterator<Type>::exprideCheck(const uint line)
{
    if (ptr.expired())
    {
        time_t curTime = time(NULL);
        throw ExpiredException(ctime(&curTime), __FILE__, line,
                               typeid(*this).name(), __FUNCTION__);
    }
}

template <typename Type>
void Iterator<Type>::indexCheck(const uint line)
{
    if (index >= size)
    {
        time_t curTime = time(NULL);
        throw OutOfRangeException(ctime(&curTime), __FILE__, line,
                               typeid(*this).name(), __FUNCTION__);
    }
}

#endif
