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

#endif
