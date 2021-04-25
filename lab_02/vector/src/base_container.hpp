#include <iostream>

#include "base_container.h"

bool BaseContainer::is_empty() const
{
    return !bool(size);
}

size_t BaseContainer::get_size() const
{
    return size;
}
