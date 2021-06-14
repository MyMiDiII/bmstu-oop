#include <iterator>

#include "scene.h"

std::vector<std::shared_ptr<Object>> Scene::get_models() {
    return _models->getObjects();
}


std::vector<std::shared_ptr<Camera>> Scene::get_viewers() {
    return _viewers;
}


std::shared_ptr<Composite> Scene::get_composite() {
    return _models;
}

void Scene::add_model(const std::shared_ptr<Object> &model)
{
    _models->add(model);
}


void Scene::remove_model(const std::size_t index)
{
    auto iter = _models->begin();

    std::advance(iter, index);
    _models->remove(iter);
}


void Scene::add_viewer(const std::shared_ptr<Camera> &viewer)
{
    _viewers.push_back(viewer);
}

void Scene::remove_viewer(const std::size_t index)
{
    auto iter = _viewers.begin();

    std::advance(iter, index);
    _viewers.erase(iter);
}




