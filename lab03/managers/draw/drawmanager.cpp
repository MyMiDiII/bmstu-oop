#include "drawmanager.h"
#include "model.h"

void DrawManager::setCamera(std::shared_ptr<Camera> camera)
{
    _camera = camera;
}


void DrawManager::setDrawer(std::shared_ptr<BaseDrawer> drawer)
{
    _drawer = drawer;
}


Vertex DrawManager::getProjection(const Vertex &dot)
{
    Vertex projection = dot;

    projection.setX(projection.getX() + _camera->getLocation().getX());
    projection.setY(projection.getY() + _camera->getLocation().getY());

    return projection;
}


void DrawManager::visit(const Model &model)
{
    auto dots = model._modelStructure->getVertexes();
    auto links = model._modelStructure->getLinks();
    auto center = model._modelStructure->getCenter();

    for (auto link : links)
    {
        _drawer->drawLine(getProjection(dots.at(link.getFirst() - 1)).getAbsVertex(center),
                          getProjection(dots.at(link.getSecond() - 1)).getAbsVertex(center));
    }

}



