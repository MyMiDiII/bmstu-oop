#ifndef ABSTRACT_DRAWER_H
#define ABSTRACT_DRAWER_H

#include "vertex.h"


class AbstractDrawer
{
public:
    AbstractDrawer() = default;
    virtual ~AbstractDrawer() = default;

    virtual void draw_line(const Dot &dot1, const Dot &dot2) = 0;
    virtual void clear_scene() = 0;
};

#endif //ABSTRACT_DRAWER_H
