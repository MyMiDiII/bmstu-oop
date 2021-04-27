#ifndef VECTOR_H
#define VECTOR_H

#include <memory>

#include "base_container.h"
#include "iterator.h"
#include "const_iterator.h"

using namespace std;

template <typename Type>
class Vector : public BaseContainer
{
    friend class Iterator<Type>;
    friend class ConstIterator<Type>;

public:
    Vector() = default;
    explicit Vector(size_t sizeValue);
    Vector(const Vector<Type> &vector);
    Vector(size_t sizeValue, Type filler);
    Vector(const initializer_list<Type> &elements);

    ~Vector() override = default;

    bool operator==(const Vector<Type> &vector) const;
    bool isEqual(const Vector<Type> &vector) const;

    bool operator!=(const Vector<Type> &vector) const;
    bool isNotEqual(const Vector<Type> &vector) const;

    template <typename OutType>
    OutType length() const;

    Type & at(const size_t index);
    const Type & at(const size_t index) const;

    Vector<Type> vecSum(const Vector<Type> &vector) const;

    Vector<Type> eqVecSum(const Vector<Type> &vector);

    Vector<Type> vecDiff(const Vector<Type> &vector) const;

    Vector<Type> eqVecDiff(const Vector<Type> &vector);

    Vector<Type> neg() const;

    Iterator<Type> begin() noexcept;
    Iterator<Type> end() noexcept;
    ConstIterator<Type> begin() const noexcept;
    ConstIterator<Type> end() const noexcept;
    ConstIterator<Type> cbegin() const noexcept;
    ConstIterator<Type> cend() const noexcept;

protected:
    void allocate(size_t sizeValue);

private:
    shared_ptr<Type[]> data = nullptr;
};

#include "vector.hpp"

#endif // VECTOR_H
