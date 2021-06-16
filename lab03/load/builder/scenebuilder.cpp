#include "scenebuilder.h"


void SceneBuilder::build()
{
    _scene = std::make_shared<Scene>();
}


void SceneBuilder::buildModel(const std::shared_ptr<Object> &object)
{
    if (isBuild()) {}

    _scene->addModel(object);
}

void SceneBuilder::buildCamera(const std::shared_ptr<Object> &camera)
{
    if (isBuild()) {}

    _scene->addCamera(camera);
}


bool SceneBuilder::isBuild() const
{
    return nullptr != _scene;
}


std::shared_ptr<Object> SceneBuilder::get()
{
    return _scene;
}
