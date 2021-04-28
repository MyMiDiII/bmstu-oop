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
    explicit Vector(const Vector<Type> &vector);
    Vector(size_t sizeValue, Type filler);
    Vector(size_t sizeValue, const Type *arr);
    Vector(const initializer_list<Type> &elements);
    Vector(Vector<Type> &&vector);
    Vector(Iterator<Type> begin, Iterator<Type> end);
    Vector(ConstIterator<Type> begin, ConstIterator<Type> end);

    ~Vector() override = default;

    Vector<Type> &operator=(const initializer_list<Type> &elements);
    Vector<Type> &operator=(const Vector<Type> &vector);
    Vector<Type> &operator=(Vector<Type> &&vector) noexcept;

    bool operator==(const Vector<Type> &vector) const;
    bool isEqual(const Vector<Type> &vector) const;

    bool operator!=(const Vector<Type> &vector) const;
    bool isNotEqual(const Vector<Type> &vector) const;

    double length() const;

    Type &at(const size_t index);
    Type &operator[](const size_t index);

    const Type &at(const size_t index) const;
    const Type &operator[](const size_t index) const;

    Vector<Type> vecSum(const Vector<Type> &vector) const;
    Vector<Type> operator+(const Vector<Type> &vector) const;

    Vector<Type> byNumSum(const Type &num) const;
    Vector<Type> operator+(const Type &num) const;

    Vector<Type> &eqVecSum(const Vector<Type> &vector);
    Vector<Type> &operator+=(const Vector<Type> &vector);

    Vector<Type> &eqByNumSum(const Type &num);
    Vector<Type> &operator+=(const Type &num);

    Vector<Type> vecDiff(const Vector<Type> &vector) const;
    Vector<Type> operator-(const Vector<Type> &vector) const;

    Vector<Type> byNumDiff(const Type &num) const;
    Vector<Type> operator-(const Type &num) const;

    Vector<Type> &eqVecDiff(const Vector<Type> &vector);
    Vector<Type> &operator-=(const Vector<Type> &vector);

    Vector<Type> &eqByNumDiff(const Type &num);
    Vector<Type> &operator-=(const Type &num);

    Vector<Type> vecProd(const Vector<Type> &vector) const;
    Vector<Type> operator*(const Vector<Type> &vector) const;

    Vector<Type> byNumProd(const Type &num) const;
    Vector<Type> operator*(const Type &num) const;

    Vector<Type> &eqVecProd(const Vector<Type> &vector);
    Vector<Type> &operator*=(const Vector<Type> &vector);

    Vector<Type> &eqByNumProd(const Type &num);
    Vector<Type> &operator*=(const Type &num);

    Vector<Type> vecQuot(const Vector<Type> &vector) const;
    Vector<Type> operator/(const Vector<Type> &vector) const;

    Vector<Type> byNumQuot(const Type &num) const;
    Vector<Type> operator/(const Type &num) const;

    Vector<Type> &eqVecQuot(const Vector<Type> &vector);
    Vector<Type> &operator/=(const Vector<Type> &vector);

    Vector<Type> &eqByNumQuot(const Type &num);
    Vector<Type> &operator/=(const Type &num);

    Vector<Type> neg() const;
    Vector<Type> operator-() const;

    Type scalarProd(const Vector<Type> &vector) const;
    Type operator&(const Vector<Type> &vector) const;

    Vector<Type> vectorProd(const Vector<Type> &vector) const;
    Vector<Type> operator^(const Vector<Type> &vector) const;

    Vector<Type> &eqVectorProd(const Vector<Type> &vector);
    Vector<Type> &operator^=(const Vector<Type> &vector);

    double angle(const Vector<Type> &vector) const;

    bool isCollinear(const Vector<Type> &vector) const;

    bool isOrthoganal(const Vector<Type> &vector) const;

    bool isZero() const;

    Iterator<Type> begin() noexcept;
    Iterator<Type> end() noexcept;
    ConstIterator<Type> begin() const noexcept;
    ConstIterator<Type> end() const noexcept;

    ConstIterator<Type> cbegin() const noexcept;
    ConstIterator<Type> cend() const noexcept;

protected:
    void allocate(size_t sizeValue);
    void zeroSizeCheck(const uint line) const;
    void indexCheck(const size_t index, const uint line) const;
    void sizesCheck(const Vector<Type> &vector, const uint line) const;
    void vectorProdSizesCheck(const Vector<Type> &vector, const uint line) const;
    void divisionByZeroCheck(const Type &num, const uint line) const;

private:
    shared_ptr<Type[]> data = nullptr;
};

#include "vector.hpp"

#endif // VECTOR_H
