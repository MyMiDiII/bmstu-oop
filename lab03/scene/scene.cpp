#include <iterator>

#include "scene.h"
#include "composite.h"

Scene::Scene() : _models(new Composite)
{

}

std::vector<std::shared_ptr<Object>> Scene::getModels()
{
    return _models->_elements;
}


std::vector<std::shared_ptr<Camera>> Scene::getCameras()
{
    return _cameras;
}


std::shared_ptr<Composite> Scene::getComposite()
{
    return _models;
}

void Scene::addModel(const std::shared_ptr<Object> &model)
{
    _models->add(model);
}


void Scene::deleteModel(const std::size_t index)
{
    auto iter = _models->begin();

    std::advance(iter, index);
    _models->remove(iter);
}


void Scene::addCamera(const std::shared_ptr<Camera> &camera)
{
    _cameras.push_back(camera);
}

void Scene::deleteCamera(const std::size_t index)
{
    auto iter = _cameras.begin();
    std::advance(iter, index);
    _cameras.erase(iter);
}




