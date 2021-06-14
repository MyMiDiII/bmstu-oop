#ifndef BASE_LOADER_SCENE_H
#define BASE_LOADER_SCENE_H

#include "baseloader.h"
#include "scenebuilder.h"

class BaseLoaderScene : public BaseLoader
{
public:
    virtual std::shared_ptr<Object> load(std::shared_ptr<SceneBuilder> builder) = 0;

protected:
    virtual void load_models(std::shared_ptr<SceneBuilder> builder) = 0;
    virtual void load_viewers(std::shared_ptr<SceneBuilder> builder) = 0;
};

#endif //BASE_LOADER_SCENE_H
