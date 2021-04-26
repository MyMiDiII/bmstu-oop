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

    bool operator==(const Vector<Type> &vector) const;

    Iterator<Type> begin() noexcept;
    Iterator<Type> end() noexcept;

protected:
    void allocate(size_t sizeValue);

private:
    shared_ptr<Type[]> data = nullptr;
};

#include "vector.hpp"

#endif // VECTOR_H
