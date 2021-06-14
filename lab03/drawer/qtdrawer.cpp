#include "qtdrawer.h"

QtDrawer::QtDrawer(QGraphicsScene *scene)
{
    _scene = scene;
}


QtDrawer::QtDrawer(const QtDrawer &drawer)
{
    _scene = drawer._scene;
}


void QtDrawer::drawLine(const Dot &vertex1, const Dot &vertex2)
{
    _scene->addLine(vertex1.get_x(), vertex1.get_y(), vertex2.get_x(), vertex2.get_y());
}


void QtDrawer::clearScene()
{
    _scene->clear();
}

