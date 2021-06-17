#ifndef CAMERA_H
#define CAMERA_H

#include "visitor.h"
#include "object.h"
#include "drawvisitor.h"

class Camera : public InvisibleObject
{
    friend Vertex DrawVisitor::getProjection(const Vertex &vertex);

public:
    Camera() = default;
    Camera(const Vertex &location) : _location(location) { }
    ~Camera() override = default;

    void transform(const Vertex &move, const Vertex &scale, const Vertex &rotate) override;
    void accept(std::shared_ptr<Visitor> visitor) override;

private:
    void moveX(const double dx);
    void moveY(const double dy);
    void moveZ(const double dz);

    Vertex _location;
};


#endif //CAMERA_H
