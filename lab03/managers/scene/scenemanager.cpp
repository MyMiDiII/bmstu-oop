#include <utility>
#include "scenemanager.h"


SceneManager::SceneManager()
{
    _scene = std::make_shared<Scene>();
}


std::shared_ptr<Scene> SceneManager::getScene() const
{
    return _scene;
}


std::shared_ptr<Viewer> SceneManager::getCamera() const
{
    return _camera;
}


void SceneManager::setScene(std::shared_ptr<Scene> scene)
{
    _scene = std::move(scene);
}


void SceneManager::setCamera(const size_t index)
{
    auto camera = _scene->get_viewers().at(index);

    _camera = camera;
}
