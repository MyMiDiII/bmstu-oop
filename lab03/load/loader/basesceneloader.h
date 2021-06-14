#ifndef BASESCENELOADER_H
#define BASESCENELOADER_H

#include "baseloader.h"
#include "scenebuilder.h"

class BaseSceneLoader : public BaseLoader
{
public:
    virtual std::shared_ptr<Object> load(std::shared_ptr<SceneBuilder> builder) = 0;

protected:
    virtual void loadModels(std::shared_ptr<SceneBuilder> builder) = 0;
    virtual void loadCameras(std::shared_ptr<SceneBuilder> builder) = 0;
};

#endif // BASESCENELOADER_H
