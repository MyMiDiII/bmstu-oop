#ifndef LOADER_VIEWER_H
#define LOADER_VIEWER_H

#include "baseloader.h"
#include "camerabuilder.h"

class BaseLoaderViewer : public BaseLoader
{
public:
    virtual std::shared_ptr<Object> load(std::shared_ptr<CameraBuilder> builder) = 0;
};

#endif //LOADER_VIEWER_H
