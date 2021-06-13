#ifndef VIEWER_H
#define VIEWER_H

#include "visitor.h"
#include "object.h"

class Viewer : public InvisibleObject
{
public:
    Viewer() = default;
    explicit Viewer(const Dot &position) : _position(position) { };
    ~Viewer() override = default;

    void transform(const Dot &new_position, const Dot &scale, const Dot &spin) override;
    void accept(std::shared_ptr<Visitor> visitor) override;

    Dot get_position();

private:
    void move_x(const double &dx);
    void move_y(const double &dy);
    void move_z(const double &dz);

    Dot _position;
};


#endif //VIEWER_H
