#include "modelcommand.h"
#include "loadmanagercreator.h"
#include "modelloadmoderatorcreator.h"
#include "scenemanagercreator.h"
//#include "../../inc/managers/transform/transform_manager_creator.h"


MoveModelCMD::MoveModelCMD(const double &dx, const double &dy, const double &dz, const std::size_t model_num) :
    _dx(dx), _dy(dy), _dz(dz), _model_num(model_num) { }


void MoveModelCMD::exec()
{
    Dot move(_dx, _dy, _dz);
    Dot scale(1, 1, 1);
    Dot spin(0, 0, 0);

    std::shared_ptr<Object> model = CreatorSceneManager().create_manager()->get_scene()->get_models().at(_model_num);
    //CreatorTransformManager().create_manager()->transform_object(model, move, scale, spin);
}

ScaleModelCMD::ScaleModelCMD(const double &kx, const double &ky, const double &kz, const std::size_t model_num) :
    _kx(kx), _ky(ky), _kz(kz), _model_num(model_num) { }

void ScaleModelCMD::exec()
{
    Dot move(0, 0, 0);
    Dot scale(_kx, _ky, _kz);
    Dot spin(0, 0, 0);

    std::shared_ptr<Object> model = CreatorSceneManager().create_manager()->get_scene()->get_models().at(_model_num);
    //CreatorTransformManager().create_manager()->transform_object(model, move, scale, spin);
}


SpinModelCMD::SpinModelCMD(const double &ox, const double &oy, const double &oz, const std::size_t model_num) :
        _ox(ox), _oy(oy), _oz(oz), _model_num(model_num) { }

void SpinModelCMD::exec()
{
    Dot move(0, 0, 0);
    Dot scale(1, 1, 1);
    Dot spin(_ox, _oy, _oz);

    std::shared_ptr<Object> model = CreatorSceneManager().create_manager()->get_scene()->get_models().at(_model_num);
    //CreatorTransformManager().create_manager()->transform_object(model, move, scale, spin);
}


TransformModelCMD::TransformModelCMD(const Dot &move, const Dot &scale, const Dot &spin, const std::size_t model_num) :
    _move(move), _scale(scale), _spin(spin), _model_num(model_num) { }

void TransformModelCMD::exec()
{
    std::shared_ptr<Object> model = CreatorSceneManager().create_manager()->get_scene()->get_models().at(_model_num);
    //CreatorTransformManager().create_manager()->transform_object(model, _move, _scale, _spin);
}

AddModelCMD::AddModelCMD(std::shared_ptr<Object> model) : _model(model) { }

void AddModelCMD::exec()
{
    CreatorSceneManager().create_manager()->get_scene()->add_model(_model);
}


RemoveModelCMD::RemoveModelCMD(const std::size_t model_num) : _model_num(model_num) { }

void RemoveModelCMD::exec()
{
    CreatorSceneManager().create_manager()->get_scene()->remove_model(_model_num);
}


CountModelCMD::CountModelCMD(const std::shared_ptr<std::size_t> &count) : _count(count) { }

void CountModelCMD::exec()
{
    (*_count) = CreatorSceneManager().create_manager()->get_scene()->get_models().size();
}


LoadModelCMD::LoadModelCMD(std::string file_name) : _file_name(file_name) { }

void LoadModelCMD::exec()
{
    auto moderator = LoadModelModeratorCreator().create_moderator();
    auto manager = CreatorLoadManager().create_manager(moderator);
    auto model = manager->load(_file_name);

    CreatorSceneManager().create_manager()->get_scene()->add_model(model);
}


ExportModelCMD::ExportModelCMD(std::string file_name) : _file_name(file_name) { }

void ExportModelCMD::exec() { }


