#ifndef CONSTITERATOR_HPP
#define CONSTITERATOR_HPP

#include <time.h>
#include "const_iterator.h"
#include "exceptions.h"

template <typename Type>
ConstIterator<Type>::ConstIterator(const Vector<Type> &vector) noexcept
{
    ptr = vector.data;
    size = vector.size;
    index = 0;
}

template <typename Type>
ConstIterator<Type>::ConstIterator(const ConstIterator<Type> &iterator) noexcept
{
    ptr = iterator.ptr;
    size = iterator.size;
    index = iterator.index;
}

template <typename Type>
ConstIterator<Type> &ConstIterator<Type>::operator=(const ConstIterator<Type> &it) noexcept
{
    ptr.reset(it.ptr);
    size = it.size;
    index = it.index;
}

template <typename Type>
ConstIterator<Type>::operator bool() const
{
    exprideCheck(__LINE__);

    return size && (index < size);
}

template <typename Type>
const Type &ConstIterator<Type>::operator*() const
{
    exprideCheck(__LINE__);
    indexCheck(__LINE__);

    return *getCurPtr();
}

template <typename Type>
const Type *ConstIterator<Type>::operator->() const
{
    exprideCheck(__LINE__);
    indexCheck(__LINE__);

    return getCurPtr();
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
ConstIterator<Type> &ConstIterator<Type>::operator+=(const size_t dif)
{
    exprideCheck(__LINE__);
    indexCheck(__LINE__);

    index += dif;
    return this;
}

template <typename Type>
ConstIterator<Type> & ConstIterator<Type>::operator++()
{
    exprideCheck(__LINE__);

    ++index;
    return *this;
}

template <typename Type>
ConstIterator<Type> ConstIterator<Type>::operator++(int)
{
    exprideCheck(__LINE__);

    ConstIterator<Type> tmp(*this);
    ++(*this);
    return tmp;
}

template <typename Type>
ConstIterator<Type> ConstIterator<Type>::operator-(const size_t dif) const
{
    exprideCheck(__LINE__);
    indexCheck(__LINE__);

    ConstIterator<Type> tmp(*this);
    tmp.index -= dif;
    return tmp;
}

template <typename Type>
ConstIterator<Type> &ConstIterator<Type>::operator-=(const size_t dif)
{
    exprideCheck(__LINE__);
    indexCheck(__LINE__);

    index -= dif;
    return this;
}

template <typename Type>
ConstIterator<Type> & ConstIterator<Type>::operator--()
{
    exprideCheck(__LINE__);

    --index;
    return *this;
}

template <typename Type>
ConstIterator<Type> ConstIterator<Type>::operator--(int)
{
    exprideCheck(__LINE__);

    ConstIterator<Type> tmp(*this);
    --(*this);
    return tmp;
}


template <typename Type>
bool ConstIterator<Type>::operator==(const ConstIterator<Type> &iterator) const
{
    exprideCheck(__LINE__);
    iterator.exprideCheck(__LINE__);

    return getCurPtr() == iterator.getCurPtr();
}

template <typename Type>
bool ConstIterator<Type>::operator!=(const ConstIterator<Type> &iterator) const
{
    return !(*this == iterator);
}

template <typename Type>
bool ConstIterator<Type>::operator>(const ConstIterator<Type> &iterator) const
{
    exprideCheck(__LINE__);
    iterator.exprideCheck(__LINE__);

    return getCurPtr() > iterator.getCurPtr();
}

template <typename Type>
bool ConstIterator<Type>::operator>=(const ConstIterator<Type> &iterator) const
{
    return !(iterator.getCurPtr() > getCurPtr());
}

template <typename Type>
bool ConstIterator<Type>::operator<(const ConstIterator<Type> &iterator) const
{
    return iterator.getCurPtr() > getCurPtr();
}

template <typename Type>
bool ConstIterator<Type>::operator<=(const ConstIterator<Type> &iterator) const
{
    return !(getCurPtr() > iterator.getCurPtr());
}

template <typename Type>
Type *ConstIterator<Type>::getCurPtr() const
{
    shared_ptr<Type[]> tmp = ptr.lock();
    return tmp.get() + index;
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
