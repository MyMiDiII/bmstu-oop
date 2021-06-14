#include "scenebuilder.h"


void SceneBuilder::build()
{
    _scene = std::make_shared<Scene>();
}


void SceneBuilder::buildModel(const std::shared_ptr<Object> &object)
{
    if (isBuild()) {}

    _scene->add_model(object);
}

void SceneBuilder::buildCamera(const std::shared_ptr<Viewer> &camera)
{
    if (isBuild()) {}

    _scene->add_viewer(camera);
}


bool SceneBuilder::isBuild() const
{
    return nullptr != _scene;
}


std::shared_ptr<Object> SceneBuilder::get()
{
    return _scene;
}
