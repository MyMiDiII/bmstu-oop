#ifndef DRAWER_QT_FACTORY_H
#define DRAWER_QT_FACTORY_H

#include "drawerfactory.h"
#include "qtdrawer.h"


class DrawerQtFactory : public AbstractDrawerFactory
{
public:
    explicit DrawerQtFactory(QGraphicsScene *scene);

    std::unique_ptr<AbstractDrawer> graphic_create() override;

private:
    QGraphicsScene *_scene;
};

#endif //DRAWER_QT_FACTORY_H
