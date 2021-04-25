#ifndef ITERATOR_H
#define ITERATOR_H

#include <memory>

using namespace std;

template <typename Type> class Vector;

template <typename Type>
class Iterator : public iterator<input_iterator_tag, Type>
{
    friend class Vector<Type>;

public:
    Iterator(const Vector<Type> &vector) noexcept;
    Iterator(const Iterator<Type> &iterator) noexcept = default;

    // перепроверить конструкторы !!!
    ~Iterator() = default;

    Type & operator*();
    Type * operator->();

    const Type & operator*() const;
    const Type * operator->() const;

    Iterator<Type> operator+(const size_t dif) const;

    Iterator<Type> & operator++() noexcept;
    Iterator<Type> operator++(int) noexcept;

    bool operator==(const Iterator<Type> &iterator) const;
    bool operator!=(const Iterator<Type> &iterator) const;

protected:
    void exprideCheck(const uint line);
    void indexCheck(const uint line);

private:
    weak_ptr<Type[]> ptr;
    size_t size = 0;
    size_t index = 0;
};

#include "iterator.hpp"

#endif // ITERATOR_H
