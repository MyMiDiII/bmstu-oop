#include "mediator.h"

void draw_line(const double x1, const double y1,
               const double x2, const double y2,
               const canvas_t &canvas)
{
    canvas.scene->addLine(x1, y1, x2, y2);
}

void clear_canvas(const canvas_t &canvas)
{
    canvas.scene->clear();
}
