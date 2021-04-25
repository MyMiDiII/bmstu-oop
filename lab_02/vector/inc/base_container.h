#ifndef BASE_CONTAINER_H
#define BASE_CONTAINER_H

#include <cstddef>

class BaseContainer
{
public:
    virtual bool is_empty() const;
    virtual size_t get_size() const;
    //virtual void clear() = 0;
    virtual ~BaseContainer() = default;

protected:
    size_t size = 0;
};

#include "base_container.hpp"

#endif // BASE_CONTAINER_H
