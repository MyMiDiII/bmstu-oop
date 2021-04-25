#ifndef VECTOR_H
#define VECTOR_H

#include <memory>

#include "base_container.h"
#include "iterator.h"

using namespace std;

template <typename Type>
class Vector : public BaseContainer
{
    friend class Iterator<Type>;

public:
    Vector() = default;
    explicit Vector(size_t sizeValue);
    Vector(size_t sizeValue, Type filler);
    Vector(const initializer_list<Type> &elements);

    ~Vector() override = default;

    Iterator<Type> begin() noexcept;
    Iterator<Type> end() noexcept;

private:
    shared_ptr<Type[]> data = nullptr;
};

#include "vector.hpp"

#endif // VECTOR_H
