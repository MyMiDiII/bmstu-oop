#ifndef CAMERABUILDER_H
#define CAMERABUILDER_H

#include "camera.h"
#include "basebuilder.h"

class CameraBuilder : public BaseBuilder
{
public:
    CameraBuilder() = default;
    ~CameraBuilder() = default;

    void build() override;
    void buildLocation(const double x, const double y, const double z);
    bool isBuild() const override;

    std::shared_ptr<Camera> get();

private:
    std::shared_ptr<Camera> _camera;
};

#endif //CAMERABUILDER_H
