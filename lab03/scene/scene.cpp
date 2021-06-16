#include <iterator>

#include "scene.h"
#include "composite.h"

Scene::Scene() : _models(new Composite), _cameras(new Composite)
{

}

std::shared_ptr<Composite> Scene::getModels()
{
    return _models;
}

std::shared_ptr<Composite> Scene::getCameras()
{
    return _cameras;
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


void Scene::addCamera(const std::shared_ptr<Object> &camera)
{
    _cameras->add(camera);
}

void Scene::deleteCamera(const std::size_t index)
{
    auto iter = _cameras->begin();
    std::advance(iter, index);
    _cameras->remove(iter);
}




