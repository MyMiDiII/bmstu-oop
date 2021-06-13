#include <utility>
#include "scenemanager.h"


SceneManager::SceneManager()
{
    _scene = std::make_shared<Scene>();
}


std::shared_ptr<Scene> SceneManager::get_scene() const {
    return _scene;
}


std::shared_ptr<Viewer> SceneManager::get_viewer() const {
    return _viewer;
}


void SceneManager::set_scene(std::shared_ptr<Scene> scene)
{
    _scene = std::move(scene);
}


void SceneManager::set_viewer(const size_t &viewer_index)
{
    auto viewer = _scene->get_viewers().at(viewer_index);

    _viewer = viewer;
}
