#include "modelcommand.h"
#include "loadmanagercreator.h"
#include "modelloadmoderatorcreator.h"
#include "scenemanagercreator.h"
#include "transformmanagercreator.h"


MoveModel::MoveModel(const double &dx, const double &dy, const double &dz, const std::size_t index) :
    _dx(dx), _dy(dy), _dz(dz), _index(index) { }


void MoveModel::execute()
{
    std::shared_ptr<Object> model = CreatorSceneManager().create_manager()->get_scene()->get_models().at(_index);
    CreatorTransformManager().create_manager()->move_object(model, _dx, _dy, _dz);
}


ScaleModel::ScaleModel(const double &kx, const double &ky, const double &kz, const std::size_t index) :
    _kx(kx), _ky(ky), _kz(kz), _index(index) { }

void ScaleModel::execute()
{
    std::shared_ptr<Object> model = CreatorSceneManager().create_manager()->get_scene()->get_models().at(_index);
    CreatorTransformManager().create_manager()->scale_object(model, _kx, _ky, _kz);
}


RotateModel::RotateModel(const double &ox, const double &oy, const double &oz, const std::size_t index) :
        _ox(ox), _oy(oy), _oz(oz), _index(index) { }

void RotateModel::execute()
{
    std::shared_ptr<Object> model = CreatorSceneManager().create_manager()->get_scene()->get_models().at(_index);
    CreatorTransformManager().create_manager()->spin_object(model, _ox, _oy, _oz);
}


TransformModel::TransformModel(const Dot &move, const Dot &scale, const Dot &rotate, const std::size_t index) :
    _move(move), _scale(scale), _rotate(rotate), _index(index) { }

void TransformModel::execute()
{
    std::shared_ptr<Object> model = CreatorSceneManager().create_manager()->get_scene()->get_models().at(_index);
    CreatorTransformManager().create_manager()->transform_object(model, _move, _scale, _rotate);
}


AddModel::AddModel(std::shared_ptr<Object> model) : _model(model) { }

void AddModel::execute()
{
    CreatorSceneManager().create_manager()->get_scene()->add_model(_model);
}


DeleteModel::DeleteModel(const std::size_t index) : _index(index) { }

void DeleteModel::execute()
{
    CreatorSceneManager().create_manager()->get_scene()->remove_model(_index);
}


CountModel::CountModel(const std::shared_ptr<std::size_t> &num) : _num(num) { }

void CountModel::execute()
{
    (*_num) = CreatorSceneManager().create_manager()->get_scene()->get_models().size();
}


LoadModel::LoadModel(std::string fileName) : _fileName(fileName) { }

void LoadModel::execute()
{
    auto moderator = ModelLoadModeratorCreator().createModerator();
    auto manager = LoadManagerCreator().createManager(moderator);
    auto model = manager->load(_fileName);

    CreatorSceneManager().create_manager()->get_scene()->add_model(model);
}
