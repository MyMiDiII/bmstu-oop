#include "drawvisitor.h"
#include "camera.h"
#include "model.h"
#include "scene.h"

void DrawVisitor::setCamera(std::shared_ptr<Camera> camera)
{
    _camera = camera;
}

void DrawVisitor::setDrawer(std::shared_ptr<BaseDrawer> drawer)
{
    _drawer = drawer;
}

Vertex DrawVisitor::getProjection(const Vertex &vertex)
{
    Vertex projection = vertex;

    projection.setX(projection.getX() + _camera->_location.getX());
    projection.setY(projection.getY() + _camera->_location.getY());

    return projection;
}


void DrawVisitor::visit(const Model &model)
{
    auto vertexes = model._modelStructure->getVertexes();
    auto links = model._modelStructure->getLinks();
    auto center = model._modelStructure->getCenter();

    for (auto link : links)
    {
        _drawer->drawLine(getProjection(vertexes.at(link.getFirst() - 1)).getAbsVertex(center),
                          getProjection(vertexes.at(link.getSecond() - 1)).getAbsVertex(center));
    }

}

void DrawVisitor::visit(const Composite &composite)
{
    for (auto &elem : composite._elements)
        elem->accept(std::make_shared<DrawVisitor>(*this));
}
