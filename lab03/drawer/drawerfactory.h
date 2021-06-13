#ifndef DRAWERFACTORY_H
#define DRAWERFACTORY_H

#include <memory>
#include "basedrawer.h"

class AbstractDrawerFactory
{
public:
    virtual std::unique_ptr<AbstractDrawer> graphic_create() = 0;
};

#endif //DRAWERFACTORY_H
