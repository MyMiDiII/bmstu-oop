#include "scenecommand.h"
#include "drawmanagercreator.h"
#include "loadmanagercreator.h"
#include "scenemanagercreator.h"
#include "transformmanagercreator.h"
#include "cameraloadmoderatorcreator.h"
#include "drawvisitorcreator.h"
#include "sceneloadmoderatorcreator.h"


DrawScene::DrawScene(std::shared_ptr<BaseDrawer> drawer) : _drawer(drawer) { }


void DrawScene::execute()
{
    auto drawManager = DrawManagerCreator().createManager();
    auto sceneManager = SceneManagerCreator().createManager();
    auto camera = sceneManager->getCamera();
    auto visitor = DrawVisitorCreator().createVisitor();
    visitor->setCamera(camera);
    visitor->setDrawer(_drawer);

    _drawer->clearScene();
    drawManager->setVisitor(visitor);
    drawManager->drawScene(sceneManager->getScene());
}


LoadScene::LoadScene(std::string fileName) : _fileName(fileName) { }

void LoadScene::execute()
{
    auto moderator = SceneLoadModeratorCreator().createModerator();
    auto manager = LoadManagerCreator().createManager();
    manager->setSceneLoader(moderator);
    auto scene = manager->loadScene(_fileName);

    SceneManagerCreator().createManager()->setScene(scene);
}
