#include <iterator>

#include "scene.h"
#include "composite.h"

#include <QDebug>

Scene::Scene() : _objects(new Composite)
{
    qDebug() << "composit is build";
}

void Scene::addObject(const std::shared_ptr<Object> &object)
{
    _objects->add(object);
}


void Scene::deleteObject(Iterator &iter)
{
    _objects->remove(iter);
}

Iterator Scene::getObject(const std::size_t id)
{
    qDebug() << id;

    auto iter = begin();

    for (; iter != end() && (*iter)->getId() != id; ++iter)
    {
        qDebug() << (*iter)->getId();
    }

    if (iter == end())
        qDebug() << "no";

    return iter;
}

Iterator Scene::begin()
{
    return _objects->begin();
}

Iterator Scene::end()
{
    return _objects->end();
}
