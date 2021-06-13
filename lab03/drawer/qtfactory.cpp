#include "qtfactory.h"

DrawerQtFactory::DrawerQtFactory(QGraphicsScene *scene)
{
    _scene = scene;
}

std::unique_ptr<AbstractDrawer> DrawerQtFactory::graphic_create()
{
    return std::unique_ptr<AbstractDrawer>(new DrawerQt(_scene));
}



