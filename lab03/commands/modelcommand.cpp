#include "modelcommand.h"
#include "loadmanagercreator.h"
#include "modelloadmoderatorcreator.h"
#include "scenemanagercreator.h"
#include "transformmanagercreator.h"


MoveModel::MoveModel(const double &dx, const double &dy, const double &dz, const std::size_t index) :
    _dx(dx), _dy(dy), _dz(dz), _index(index) { }


void MoveModel::execute()
{
    auto iter = SceneManagerCreator().createManager()->getScene()->getModels()->begin();
    std::advance(iter, _index);
    std::shared_ptr<Object> model = *iter;

    TransformManagerCreator().createManager()->moveObject(model, _dx, _dy, _dz);
}


ScaleModel::ScaleModel(const double &kx, const double &ky, const double &kz, const std::size_t index) :
    _kx(kx), _ky(ky), _kz(kz), _index(index) { }

void ScaleModel::execute()
{
    auto iter = SceneManagerCreator().createManager()->getScene()->getModels()->begin();
    std::advance(iter, _index);
    std::shared_ptr<Object> model = *iter;

    TransformManagerCreator().createManager()->scaleObject(model, _kx, _ky, _kz);
}


RotateModel::RotateModel(const double &ox, const double &oy,
                         const double &oz, const std::size_t index) :
        _ox(ox), _oy(oy), _oz(oz), _index(index) { }

void RotateModel::execute()
{
    auto iter = SceneManagerCreator().createManager()->getScene()->getModels()->begin();
    std::advance(iter, _index);
    std::shared_ptr<Object> model = *iter;

    TransformManagerCreator().createManager()->rotateObject(model, _ox, _oy, _oz);
}


TransformModel::TransformModel(const Vertex &move, const Vertex &scale,
                               const Vertex &rotate, const std::size_t index) :
    _move(move), _scale(scale), _rotate(rotate), _index(index) { }

void TransformModel::execute()
{
    auto iter = SceneManagerCreator().createManager()->getScene()->getModels()->begin();
    std::advance(iter, _index);
    std::shared_ptr<Object> model = *iter;

    TransformManagerCreator().createManager()->transformObject(model, _move, _scale, _rotate);
}


AddModel::AddModel(std::shared_ptr<Object> model) : _model(model) { }

void AddModel::execute()
{
    SceneManagerCreator().createManager()->getScene()->addModel(_model);
}


DeleteModel::DeleteModel(const std::size_t index) : _index(index) { }

void DeleteModel::execute()
{
    SceneManagerCreator().createManager()->getScene()->deleteModel(_index);
}


CountModel::CountModel(const std::shared_ptr<std::size_t> &num) : _num(num) { }

void CountModel::execute()
{
    auto scene = \
            SceneManagerCreator().createManager()->getScene();

    auto begin = scene->getModels()->begin();
    auto end = scene->getCameras()->end();

    (*_num) = end - begin;
}


LoadModel::LoadModel(std::string fileName) : _fileName(fileName) { }

void LoadModel::execute()
{
    auto moderator = ModelLoadModeratorCreator().createModerator();
    auto manager = LoadManagerCreator().createManager(moderator);
    auto model = manager->load(_fileName);

    SceneManagerCreator().createManager()->getScene()->addModel(model);
}
