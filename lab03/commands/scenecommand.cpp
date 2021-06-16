#include "scenecommand.h"
#include "drawmanagercreator.h"
#include "loadmanagercreator.h"
#include "scenemanagercreator.h"
#include "transformmanagercreator.h"
#include "sceneloadmoderatorcreator.h"


DrawScene::DrawScene(std::shared_ptr<BaseDrawer> drawer) : _drawer(drawer) { }


void DrawScene::execute()
{
    auto drawManager = DrawManagerCreator().createManager();
    auto sceneManager = SceneManagerCreator().createManager();
    auto camera = sceneManager->getCamera();

    _drawer->clearScene();
    drawManager->setDrawer(_drawer);
    drawManager->setCamera(camera);
    sceneManager->getScene()->getModels()->accept(drawManager);
}


LoadScene::LoadScene(std::string fileName) : _fileName(fileName) { }

void LoadScene::execute()
{
    auto moderator = SceneLoadModeratorCreator().createModerator();
    auto manager = LoadManagerCreator().createManager(moderator);
    auto scene = std::dynamic_pointer_cast<Scene>(manager->load(_fileName));

    SceneManagerCreator().createManager()->setScene(scene);
}
