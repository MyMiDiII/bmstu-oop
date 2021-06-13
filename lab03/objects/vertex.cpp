#include <cmath>

#include "vertex.h"

double to_radians(const double &angle)
{
    return angle * (M_PI / 180);
}

Dot::Dot(const double x, const double y, const double z)
{
    set_x(x);
    set_y(y);
    set_z(z);
}


Dot::Dot(const Dot &&dot) noexcept
{
    set_x(dot._x);
    set_y(dot._y);
    set_z(dot._z);

    dot.~Dot();
}


Dot &Dot::operator = (Dot &&dot) noexcept
{
    set_x(dot._x);
    set_y(dot._y);
    set_z(dot._z);

    dot.~Dot();

    return *this;
}

double Dot::get_x() const
{
    return _x;
}

double Dot::get_y() const
{
    return _y;
}

double Dot::get_z() const
{
    return _z;
}

void Dot::set_x(const double &x)
{
    _x = x;
}

void Dot::set_y(const double &y)
{
    _y = y;
}

void Dot::set_z(const double &z)
{
    _z = z;
}

bool Dot::operator == (const Dot &dot) const noexcept
{
    return (dot._x == _x) && (dot._y == _y) && (dot._z == _z);
}

bool Dot::is_equal(const Dot &dot) const noexcept
{
    return *this == dot;
}

bool Dot::operator != (const Dot &dot) const noexcept
{
    return !(*this == dot);
}

bool Dot::is_not_equal(const Dot &dot) const noexcept {
    return !(*this == dot);
}

Dot Dot::operator + (const Dot &dot)
{
    Dot d{*this};

    d.set_x(d._x + dot._x);
    d.set_y(d._y + dot._y);
    d.set_z(d._z + dot._z);

    return d;
}

Dot Dot::operator - (const Dot &dot)
{
    Dot d{*this};

    d.set_x(d._x - dot._x);
    d.set_y(d._y - dot._y);
    d.set_z(d._z - dot._z);

    return d;
}


void Dot::move(const double dx, const double dy, const double dz)
{
    set_x(_x + dx);
    set_y(_y + dy);
    set_z(_y + dz);
}

void Dot::scale(const double kx, const double ky, const double kz)
{
    set_x(_x * kx);
    set_y(_y * ky);
    set_z(_z * kz);
}

void Dot::spin(const double ox, const double oy, const double oz)
{
    spin_x(ox);
    spin_y(oy);
    spin_z(oz);
}


void Dot::spin_x(const double &ox)
{
    const double cos_spin = cos(to_radians(ox));
    const double sin_spin = sin(to_radians(ox));

    const double tmp = _y;

    set_y(_y * cos_spin + _z * sin_spin);
    set_z(_z * cos_spin - tmp * sin_spin);
}


void Dot::spin_y(const double &oy)
{
    const double cos_spin = cos(to_radians(oy));
    const double sin_spin = sin(to_radians(oy));

    const double tmp = _x;

    set_x(_x * cos_spin + _z * sin_spin);
    set_z(_z * cos_spin - tmp * sin_spin);
}


void Dot::spin_z(const double &oz)
{
    const double cos_spin = cos(to_radians(oz));
    const double sin_spin = sin(to_radians(oz));

    const double tmp = _x;

    set_x(_x * cos_spin + _y * sin_spin);
    set_y(_y * cos_spin - tmp * sin_spin);
}

Dot Dot::with_center(const Dot &center) {
    return (*this) + center;
}
