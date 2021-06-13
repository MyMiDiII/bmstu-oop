#ifndef QTFACTORY_H
#define QTFACTORY_H

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

#endif //QTFACTORY_H
