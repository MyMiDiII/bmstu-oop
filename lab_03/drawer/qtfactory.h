#ifndef QTFACTORY_H
#define QTFACTORY_H

#include "drawerfactory.h"
#include "qtdrawer.h"


class QtFactory : public DrawerFactory
{
public:
    explicit QtFactory(QGraphicsScene *scene);

    std::unique_ptr<BaseDrawer> createDrawer() override;

private:
    QGraphicsScene *_scene;
};

#endif //QTFACTORY_H
