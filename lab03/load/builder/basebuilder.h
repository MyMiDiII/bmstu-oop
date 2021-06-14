#ifndef BASEBUILDER_H
#define BASEBUILDER_H

#include "object.h"

class BaseBuilder
{
public:
    BaseBuilder() = default;
    ~BaseBuilder() = default;

    virtual std::shared_ptr<Object> get() = 0;

    virtual void build() = 0;
    virtual bool is_build() const = 0;
};

#endif //BASEBUILDER_H
