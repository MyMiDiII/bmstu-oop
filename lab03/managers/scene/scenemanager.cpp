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


std::shared_ptr<Camera> SceneManager::getCamera() const
{
    return _camera;
}


void SceneManager::setScene(std::shared_ptr<Scene> scene)
{
    _scene = std::move(scene);
}


void SceneManager::setCamera(const size_t index)
{
    if (_scene->getCameras()->begin() == _scene->getCameras()->end())
    {
        _camera = nullptr;
        return;
    }

    auto it = _scene->getCameras()->begin();
    std::advance(it, index);
    auto camera = *it;

    _camera = std::dynamic_pointer_cast<Camera>(camera);
}
