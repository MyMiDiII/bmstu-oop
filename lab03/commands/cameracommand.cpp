#include "cameracommand.h"
#include "camera.h"
#include "scenemanagercreator.h"
#include "transformmanagercreator.h"

#include <QDebug>

AddCamera::AddCamera(const ID & id, const double x, const double y, const double z) :
    _x(x), _y(y), _z(z), _id(id) {}

void AddCamera::execute()
{
    Vertex location(_x, _y, _z);

    std::shared_ptr<Camera> camera(new Camera(location));

    auto sceneManager = SceneManagerCreator().createManager();
    sceneManager->getScene()->addObject(camera);

    (*_id) = camera->getId();
};


DeleteCamera::DeleteCamera(const std::size_t id) : _id(id) {}

void DeleteCamera::execute()
{
    auto scene = SceneManagerCreator().createManager()->getScene();
    Iterator objIt = scene->getObject(_id);
    scene->deleteObject(objIt);
}


MoveCamera::MoveCamera(const double dx, const double dy, const size_t id) :
    _dx(dx), _dy(dy), _id(id) {}

void MoveCamera::execute()
{
    auto scene = SceneManagerCreator().createManager()->getScene();

    auto camIt = scene->getObject(_id);
    auto camera = *camIt;
    TransformManagerCreator().createManager()->moveObject(camera, _dx, _dy, 0);
}


SetCamera::SetCamera(const std::size_t id) : _id(id) {}

void SetCamera::execute()
{
    SceneManagerCreator().createManager()->setCamera(_id);
}
