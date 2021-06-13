#include "qtdrawer.h"


DrawerQt::DrawerQt(QGraphicsScene *scene)
{
    _scene = scene;
}


DrawerQt::DrawerQt(const DrawerQt &drawer)
{
    _scene = drawer._scene;
}


void DrawerQt::draw_line(const Dot &dot1, const Dot &dot2)
{
    _scene->addLine(dot1.get_x(), dot1.get_y(), dot2.get_x(), dot2.get_y());
}


void DrawerQt::clear_scene()
{
    _scene->clear();
}

