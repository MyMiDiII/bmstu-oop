#include "cameracommand.h"
#include "camera.h"
#include "scenemanagercreator.h"
#include "transformmanagercreator.h"

AddCamera::AddCamera(const double x, const double y, const double z) :
    _x(x), _y(y), _z(z) {}

void AddCamera::execute()
{
    Vertex location(_x, _y, _z);

    std::shared_ptr<Camera> camera(new Camera);

    camera->transform(location, location, location);

    auto sceneManager = SceneManagerCreator().createManager();
    sceneManager->getScene()->addCamera(camera);
    //sceneManager->setCamera(sceneManager->getScene()->getCameras().size() - 1);
};


DeleteCamera::DeleteCamera(const size_t index) : _index(index) {}

void DeleteCamera::execute()
{
    SceneManagerCreator().createManager()->getScene()->deleteCamera(_index);
}


MoveCamera::MoveCamera(const size_t index, const double dx, const double dy) :
    _dx(dx), _dy(dy), _index(index) {}

void MoveCamera::execute()
{
    auto scene = \
            SceneManagerCreator().createManager()->getScene();

    auto camIt = scene->getCameras()->begin();
    std::advance(camIt , _index);
    auto camera = *camIt;
    TransformManagerCreator().createManager()->moveObject(camera, _dx, _dy, 0);
}


SetCamera::SetCamera(const size_t index) : _index(index) {}

void SetCamera::execute()
{
    SceneManagerCreator().createManager()->setCamera(_index);
}


CountCamera::CountCamera(const std::shared_ptr<size_t> num) : _num(num) {}

void CountCamera::execute()
{
    auto scene = \
            SceneManagerCreator().createManager()->getScene();

    auto camBegin = scene->getCameras()->begin();
    auto camEnd = scene->getCameras()->end();

    (*_num) = 0;
    for (auto it = camBegin; it != camEnd; it++, (*_num)++);
}
