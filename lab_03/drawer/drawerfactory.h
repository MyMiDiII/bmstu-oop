#ifndef DRAWERFACTORY_H
#define DRAWERFACTORY_H

#include <memory>
#include "basedrawer.h"

class DrawerFactory
{
public:
    virtual std::unique_ptr<BaseDrawer> createDrawer() = 0;
};

#endif //DRAWERFACTORY_H
