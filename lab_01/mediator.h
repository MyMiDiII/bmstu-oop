#ifndef MEDIATOR_H
#define MEDIATOR_H

#include <QGraphicsScene>

struct canvas_t
{
    QGraphicsScene *scene;
    double width;
    double height;
};

void draw_line(const double x1, const double y1,
               const double x2, const double y2,
               const canvas_t &canvas);

void clear_canvas(const canvas_t &canvas);

#endif // MEDIATOR_H
