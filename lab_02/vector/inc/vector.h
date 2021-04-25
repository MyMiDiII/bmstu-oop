#ifndef VECTOR_H
#define VECTOR_H

#include <memory>

#include "base_container.h"

template <typename Type>
class Vector : public BaseContainer
{
public:
    Vector() = default;

    ~Vector() override = default;

private:
    std::shared_ptr<Type[]> data = nullptr;
};

#endif // VECTOR_H
