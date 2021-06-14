#include "scenecommand.h"
#include "drawmanagercreator.h"
#include "loadmanagercreator.h"
#include "scenemanagercreator.h"
#include "transformmanagercreator.h"
#include "sceneloadmoderatorcreator.h"


DrawScene::DrawScene(std::shared_ptr<BaseDrawer> drawer) : _drawer(drawer) { }


void DrawScene::execute()
{
    auto draw_manager = CreatorDrawManager().create_manager();
    auto scene_manager = CreatorSceneManager().create_manager();
    auto viewer = scene_manager->get_viewer();

    _drawer->clearScene();
    draw_manager->set_drawer(_drawer);
    draw_manager->set_viewer(viewer);
    scene_manager->get_scene()->get_composite()->accept(draw_manager);
}


LoadScene::LoadScene(std::string fileName) : _fileName(fileName) { }

void LoadScene::execute()
{
    auto moderator = LoadSceneModeratorCreator().create_moderator();
    auto manager = CreatorLoadManager().create_manager(moderator);
    auto scene = std::dynamic_pointer_cast<Scene>(manager->load(_fileName));

    CreatorSceneManager().create_manager()->set_scene(scene);
}
