#include "camera.h"

void Viewer::move_x(const double &dx)
{
    _position.set_x(_position.get_x() + dx);
}


void Viewer::move_y(const double &dy)
{
    _position.set_y(_position.get_y() + dy);
}


void Viewer::move_z(const double &dz)
{
    _position.set_z(_position.get_z() + dz);
}


void Viewer::transform(const Dot &new_position, const Dot &scale, const Dot &spin)
{
    move_x(new_position.get_x());
    move_y(new_position.get_y());
}


Dot Viewer::get_position()
{
    return _position;
}


void Viewer::accept(std::shared_ptr<Visitor> visitor)
{
    visitor->visit(*this);
}
