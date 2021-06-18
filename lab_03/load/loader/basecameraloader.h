#ifndef BASECAMERALOADER_H
#define BASECAMERALOADER_H

#include "baseloader.h"
#include "camerabuilder.h"

class BaseCameraLoader : public BaseLoader
{
public:
    virtual std::shared_ptr<Camera> load(std::shared_ptr<CameraBuilder> builder) = 0;
};

#endif // BASECAMERALOADER_H
