#include <iostream>

#include "base_container.h"

bool BaseContainer::isEmpty() const
{
    return !bool(size);
}

size_t BaseContainer::getSize() const
{
    return size;
}

BaseContainer::~BaseContainer() = default;
