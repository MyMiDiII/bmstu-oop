#ifndef DRAWER_FACTORY_H
#define DRAWER_FACTORY_H

#include <memory>
#include "basedrawer.h"

class AbstractDrawerFactory
{
public:
    virtual std::unique_ptr<AbstractDrawer> graphic_create() = 0;
};

#endif //DRAWER_FACTORY_H
