#ifndef CONSTITERATOR_HPP
#define CONSTITERATOR_HPP

#include <time.h>
#include "const_iterator.h"
#include "exceptions.h"

// разобраться с умными указателями
// реализовать больше операторов?

template <typename Type>
ConstIterator<Type>::ConstIterator(const Vector<Type> &vector) noexcept
{
    ptr = vector.data;
    size = vector.size;
    index = 0;
}

template <typename Type>
const Type &ConstIterator<Type>::operator*() const
{
    exprideCheck(__LINE__);
    indexCheck(__LINE__);

    return ptr.lock()[index];
}

// Указатель?
template <typename Type>
const Type *ConstIterator<Type>::operator->() const
{
    exprideCheck(__LINE__);
    indexCheck(__LINE__);

    return ptr.lock() + index;
}

template <typename Type>
ConstIterator<Type> & ConstIterator<Type>::operator++() noexcept
{
    ++index;
    return *this;
}

template <typename Type>
ConstIterator<Type> ConstIterator<Type>::operator++(int) noexcept
{
    ConstIterator<Type> tmp(*this);
    ++(*this);
    return tmp;
}

template <typename Type>
ConstIterator<Type> ConstIterator<Type>::operator+(const size_t dif) const
{
    exprideCheck(__LINE__);
    indexCheck(__LINE__);

    ConstIterator<Type> tmp(*this);
    tmp.index += dif;
    return tmp;
}

template <typename Type>
bool ConstIterator<Type>::operator==(const ConstIterator<Type> &iterator) const
{
    return ptr.lock() == iterator.ptr.lock() && index == iterator.index;
}

template <typename Type>
bool ConstIterator<Type>::operator!=(const ConstIterator<Type> &iterator) const
{
    return !(*this == iterator);
}

template <typename Type>
void ConstIterator<Type>::exprideCheck(const uint line) const
{
    if (ptr.expired())
    {
        time_t curTime = time(NULL);
        throw ExpiredException(ctime(&curTime), __FILE__, line,
                               typeid(*this).name(), __FUNCTION__);
    }
}

template <typename Type>
void ConstIterator<Type>::indexCheck(const uint line) const
{
    if (index >= size)
    {
        time_t curTime = time(NULL);
        throw OutOfRangeException(ctime(&curTime), __FILE__, line,
                               typeid(*this).name(), __FUNCTION__);
    }
}

#endif // CONSTITERATOR_HPP
