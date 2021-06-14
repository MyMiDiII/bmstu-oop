#include "cameracommand.h"
#include "camera.h"
#include "scenemanagercreator.h"
#include "transformmanagercreator.h"

AddCamera::AddCamera(const double x, const double y, const double z) :
    _x(x), _y(y), _z(z) {}

void AddCamera::execute()
{
    Vertex viewer_place(_x, _y, _z);

    std::shared_ptr<Camera> viewer(new Camera);

    viewer->transform(viewer_place, viewer_place, viewer_place);

    auto sceneManager = SceneManagerCreator().createManager();
    sceneManager->getScene()->addCamera(viewer);
    sceneManager->setCamera(sceneManager->getScene()->getCameras().size() - 1);
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
    auto viewer = \
            SceneManagerCreator().createManager()->getScene()->getCameras().at(_index);
    TransformManagerCreator().createManager()->moveObject(viewer, _dx, _dy, 0);
}


SetCamera::SetCamera(const size_t index) : _index(index) {}

void SetCamera::execute()
{
    SceneManagerCreator().createManager()->setCamera(_index);
}


CountCamera::CountCamera(const std::shared_ptr<size_t> num) : _num(num) {}

void CountCamera::execute()
{
    (*_num) = SceneManagerCreator().createManager()->getScene()->getCameras().size();
}
