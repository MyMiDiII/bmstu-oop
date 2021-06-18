#include "modelcommand.h"
#include "loadmanagercreator.h"
#include "modelloadmoderatorcreator.h"
#include "scenemanagercreator.h"
#include "transformmanagercreator.h"

#include <QDebug>


MoveModel::MoveModel(const double dx, const double dy, const double dz, const std::size_t id) :
    _dx(dx), _dy(dy), _dz(dz), _id(id) { }


void MoveModel::execute()
{
    auto scene = SceneManagerCreator().createManager()->getScene();

    auto iter = scene->getObject(_id);
    auto model = *iter;
    TransformManagerCreator().createManager()->moveObject(model, _dx, _dy, _dz);
}


ScaleModel::ScaleModel(const double kx, const double ky, const double kz, const std::size_t id) :
    _kx(kx), _ky(ky), _kz(kz), _id(id) { }

void ScaleModel::execute()
{
    auto scene = SceneManagerCreator().createManager()->getScene();

    auto iter = scene->getObject(_id);
    auto model = *iter;
    TransformManagerCreator().createManager()->scaleObject(model, _kx, _ky, _kz);
}


RotateModel::RotateModel(const double ox, const double oy,
                         const double oz, const std::size_t id) :
        _ox(ox), _oy(oy), _oz(oz), _id(id) { }

void RotateModel::execute()
{
    auto scene = SceneManagerCreator().createManager()->getScene();

    auto iter = scene->getObject(_id);
    auto model = *iter;
    TransformManagerCreator().createManager()->rotateObject(model, _ox, _oy, _oz);
}


TransformModel::TransformModel(const Vertex &move, const Vertex &scale,
                               const Vertex &rotate, const std::size_t id) :
    _move(move), _scale(scale), _rotate(rotate), _id(id) { }

void TransformModel::execute()
{
    auto scene = SceneManagerCreator().createManager()->getScene();

    auto iter = scene->getObject(_id);
    auto model = *iter;
    TransformManagerCreator().createManager()->transformObject(model, _move, _scale, _rotate);
}


DeleteModel::DeleteModel(const std::size_t id) : _id(id) { }

void DeleteModel::execute()
{
    auto scene = SceneManagerCreator().createManager()->getScene();
    Iterator objIt = scene->getObject(_id);
    scene->deleteObject(objIt);
}


LoadModel::LoadModel(const ID &id, std::string &fileName) : _fileName(fileName), _id(id) { }

void LoadModel::execute()
{
    auto moderator = ModelLoadModeratorCreator().createModerator();
    auto manager = LoadManagerCreator().createManager();
    manager->setLoader(moderator);
    auto model = manager->load(_fileName);

    SceneManagerCreator().createManager()->getScene()->addObject(model);

    (*_id) = model->getId();
}
