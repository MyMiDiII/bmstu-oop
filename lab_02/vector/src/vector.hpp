#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "vector.h"

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
Vector<Type>::Vector(size_t sizeValue)
{
    // обработка ошибки выделения памяти
    this->data.reset(new Type[sizeValue]);
    size = sizeValue;
}

template <typename Type>
Vector<Type>::Vector(size_t sizeValue, Type filler)
{
    // обработка ошибки выделения памяти
    this->data.reset(new Type[sizeValue]);
    size = sizeValue;

    for (Iterator<Type> It = begin(); It != end(); ++It)
        *It = filler;
}

template <typename Type>
Vector<Type>::Vector(const initializer_list<Type> &elements)
{
    size = elements.size();
    this->data.reset(new Type[size]);

    Iterator<Type> It = begin();

    for (auto elem : elements)
        *(It++) = elem;
}

#endif
