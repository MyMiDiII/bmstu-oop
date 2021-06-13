#ifndef QTDRAWER_H
#define QTDRAWER_QT_H

#include <QGraphicsScene>
#include "basedrawer.h"


class DrawerQt : public AbstractDrawer
{
public:
    DrawerQt() = delete;
    explicit DrawerQt(QGraphicsScene *scene);
    DrawerQt(const DrawerQt &drawer);

    void draw_line(const Dot &dot1, const Dot &dot2) override;
    void clear_scene() override;

private:
    QGraphicsScene *_scene;
};

#endif //QTDRAWER_H
