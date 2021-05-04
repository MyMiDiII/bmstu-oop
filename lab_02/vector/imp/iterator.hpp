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
Iterator<Type>::Iterator(const Iterator<Type> &iterator) noexcept
{
    ptr = iterator.ptr;
    size = iterator.size;
    index = iterator.index;
}

template <typename Type>
Iterator<Type> &Iterator<Type>::operator=(const Iterator<Type> &it) noexcept
{
    ptr.reset(it.ptr);
    size = it.size;
    index = it.index;
}

template <typename Type>
Iterator<Type>::operator bool() const
{
    exprideCheck(__LINE__);

    return size && index < size;
}

template <typename Type>
Type &Iterator<Type>::operator*()
{
    exprideCheck(__LINE__);
    indexCheck(__LINE__);

    return *getCurPtr();
}

template <typename Type>
const Type &Iterator<Type>::operator*() const
{
    exprideCheck(__LINE__);
    indexCheck(__LINE__);

    return *getCurPtr();
}

template <typename Type>
Type *Iterator<Type>::operator->()
{
    exprideCheck(__LINE__);
    indexCheck(__LINE__);

    return getCurPtr();
}

template <typename Type>
const Type *Iterator<Type>::operator->() const
{
    exprideCheck(__LINE__);
    indexCheck(__LINE__);

    return getCurPtr();
}

template <typename Type>
Iterator<Type> Iterator<Type>::operator+(const size_t dif) const
{
    exprideCheck(__LINE__);
    indexCheck(__LINE__);

    Iterator<Type> tmp(*this);
    tmp.index += dif;
    return tmp;
}

template <typename Type>
Iterator<Type> &Iterator<Type>::operator+=(const size_t dif)
{
    exprideCheck(__LINE__);
    indexCheck(__LINE__);

    index += dif;
    return this;
}

template <typename Type>
Iterator<Type> & Iterator<Type>::operator++()
{
    exprideCheck(__LINE__);

    ++index;
    return *this;
}

template <typename Type>
Iterator<Type> Iterator<Type>::operator++(int)
{
    exprideCheck(__LINE__);

    Iterator<Type> tmp(*this);
    ++(*this);
    return tmp;
}

template <typename Type>
Iterator<Type> Iterator<Type>::operator-(const size_t dif) const
{
    exprideCheck(__LINE__);
    indexCheck(__LINE__);

    Iterator<Type> tmp(*this);
    tmp.index -= dif;
    return tmp;
}

template <typename Type>
Iterator<Type> &Iterator<Type>::operator-=(const size_t dif)
{
    exprideCheck(__LINE__);
    indexCheck(__LINE__);

    index -= dif;
    return this;
}

template <typename Type>
Iterator<Type> & Iterator<Type>::operator--()
{
    exprideCheck(__LINE__);

    --index;
    return *this;
}

template <typename Type>
Iterator<Type> Iterator<Type>::operator--(int)
{
    exprideCheck(__LINE__);

    Iterator<Type> tmp(*this);
    --(*this);
    return tmp;
}


template <typename Type>
bool Iterator<Type>::operator==(const Iterator<Type> &iterator) const
{
    exprideCheck(__LINE__);
    iterator.exprideCheck(__LINE__);

    return getCurPtr() == iterator.getCurPtr();
}

template <typename Type>
bool Iterator<Type>::operator!=(const Iterator<Type> &iterator) const
{
    return !(*this == iterator);
}

template <typename Type>
bool Iterator<Type>::operator>(const Iterator<Type> &iterator) const
{
    exprideCheck(__LINE__);
    iterator.exprideCheck(__LINE__);

    return getCurPtr() > iterator.getCurPtr();
}

template <typename Type>
bool Iterator<Type>::operator>=(const Iterator<Type> &iterator) const
{
    return !(iterator.getCurPtr() > getCurPtr());
}

template <typename Type>
bool Iterator<Type>::operator<(const Iterator<Type> &iterator) const
{
    return iterator.getCurPtr() > getCurPtr();
}

template <typename Type>
bool Iterator<Type>::operator<=(const Iterator<Type> &iterator) const
{
    return !(getCurPtr() > iterator.getCurPtr());
}

template <typename Type>
Type *Iterator<Type>::getCurPtr() const
{
    shared_ptr<Type[]> tmp = ptr.lock();
    return tmp.get() + index;
}

template <typename Type>
void Iterator<Type>::exprideCheck(const uint line) const
{
    if (ptr.expired())
    {
        time_t curTime = time(NULL);
        throw ExpiredException(ctime(&curTime), __FILE__, line,
                               typeid(*this).name(), __FUNCTION__);
    }
}

template <typename Type>
void Iterator<Type>::indexCheck(const uint line) const
{
    if (index >= size)
    {
        time_t curTime = time(NULL);
        throw OutOfRangeException(ctime(&curTime), __FILE__, line,
                               typeid(*this).name(), __FUNCTION__);
    }
}

#endif
