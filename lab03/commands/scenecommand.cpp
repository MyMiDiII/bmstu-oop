#include "scenecommand.h"
#include "drawmanagercreator.h"
#include "loadmanagercreator.h"
#include "scenemanagercreator.h"
//#include "../../inc/managers/load/load_scene_moderator_creator.h"


DrawSceneCMD::DrawSceneCMD(std::shared_ptr<AbstractDrawer> drawer) : _drawer(drawer) { }


void DrawSceneCMD::exec()
{
    auto draw_manager = CreatorDrawManager().create_manager();
    auto scene_manager = CreatorSceneManager().create_manager();
    auto viewer = scene_manager->get_viewer();

    _drawer->clear_scene();
    draw_manager->set_drawer(_drawer);
    draw_manager->set_viewer(viewer);
    scene_manager->get_scene()->get_composite()->accept(draw_manager);
}


LoadSceneCMD::LoadSceneCMD(std::string file_name) : _file_name(file_name) { }

void LoadSceneCMD::exec()
{
    /*
    auto moderator = LoadSceneModeratorCreator().create_moderator();
    auto manager = CreatorLoadManager().create_manager(moderator);
    auto scene = std::dynamic_pointer_cast<Scene>(manager->load(_file_name));

    CreatorSceneManager().create_manager()->set_scene(scene);
    */
}
