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

    std::shared_ptr<Object> get() override;

private:
    std::shared_ptr<Viewer> _camera;
};

#endif //CAMERABUILDER_H
