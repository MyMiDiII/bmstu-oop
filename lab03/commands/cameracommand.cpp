//
// Created by amunra23 on 22.05.2021.
//

#include "cameracommand.h"
#include "camera.h"
#include "scenemanagercreator.h"
//#include "../../inc/managers/transform/transform_manager_creator.h"

AddViewerCommand::AddViewerCommand(const double x, const double y, const double z) : _x(x), _y(y), _z(z) {}


void AddViewerCommand::exec()
{
    Dot viewer_place(_x, _y, _z);

    std::shared_ptr<Viewer> viewer(new Viewer);

    viewer->transform(viewer_place, viewer_place, viewer_place);

    auto scene_manager = CreatorSceneManager().create_manager();
    scene_manager->get_scene()->add_viewer(viewer);
    scene_manager->set_viewer(scene_manager->get_scene()->get_viewers().size() - 1);
};


RemoveViewerCommand::RemoveViewerCommand(const size_t &viewer_num) : _viewer_num(viewer_num) { }


void RemoveViewerCommand::exec()
{
    CreatorSceneManager().create_manager()->get_scene()->remove_viewer(_viewer_num);
}


MoveViewerCommand::MoveViewerCommand(const size_t &viewer_num, const double &dx, const double &dy) : _dx(dx), _dy(dy), _viewer_num(viewer_num) { }

void MoveViewerCommand::exec()
{
    Dot move(_dx, _dy, 0);

    auto viewer = CreatorSceneManager().create_manager()->get_scene()->get_viewers().at(_viewer_num);

    //CreatorTransformManager().create_manager()->transform_object(viewer, move, move, move);
}


SetViewerCommand::SetViewerCommand(const size_t &viewer_num) : _viewer_num(viewer_num) { }


void SetViewerCommand::exec()
{
    CreatorSceneManager().create_manager()->set_viewer(_viewer_num);
}


CountViewerCommand::CountViewerCommand(const std::shared_ptr<size_t> &count) : _count(count) { }


void CountViewerCommand::exec()
{
    (*_count) = CreatorSceneManager().create_manager()->get_scene()->get_viewers().size();
}



