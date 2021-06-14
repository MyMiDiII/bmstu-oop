#include "drawmanager.h"
#include "model.h"

void DrawManager::setCamera(std::shared_ptr<Viewer> camera)
{
    _camera = camera;
}


void DrawManager::setDrawer(std::shared_ptr<BaseDrawer> drawer)
{
    _drawer = drawer;
}


Dot DrawManager::getProjection(const Dot &dot)
{
    Dot projection = dot;

    projection.set_x(projection.get_x() + _camera->get_position().get_x());
    projection.set_y(projection.get_y() + _camera->get_position().get_y());

    return projection;
}


void DrawManager::visit(const Model &model)
{
    auto dots = model._modelStructure->get_dots();
    auto links = model._modelStructure->get_links();
    auto center = model._modelStructure->get_center();

    for (auto link : links)
    {
        _drawer->drawLine(getProjection(dots.at(link.get_dot1_index() - 1)).with_center(center),
                          getProjection(dots.at(link.get_dot2_index() - 1)).with_center(center));
    }

}



