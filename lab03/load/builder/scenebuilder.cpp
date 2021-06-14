#include "scenebuilder.h"


void BuilderScene::build()
{
    _scene_ptr = std::make_shared<Scene>();
}


void BuilderScene::build_model(const std::shared_ptr<Object> &object)
{
    if (is_build()) {}

    _scene_ptr->add_model(object);
}

void BuilderScene::build_viewer(const std::shared_ptr<Viewer> &viewer)
{
    if (is_build()) {}

    _scene_ptr->add_viewer(viewer);
}


bool BuilderScene::is_build() const
{
    return nullptr != _scene_ptr;
}


std::shared_ptr<Object> BuilderScene::get()
{
    return _scene_ptr;
}
