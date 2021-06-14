#ifndef BASEDRAWER_H
#define BASEDRAWER_H

#include "vertex.h"


class BaseDrawer
{
public:
    BaseDrawer() = default;
    virtual ~BaseDrawer() = default;

    virtual void drawLine(const Dot &vertex1, const Dot &vertex2) = 0;
    virtual void clearScene() = 0;
};

#endif //BASEDRAWER_H
