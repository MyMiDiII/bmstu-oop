//
// Created by amunra23 on 22.05.2021.
//

#include "modelcommand.h"
#include "loadmanagercreator.h"
#include "modelloadmoderatorcreator.h"
#include "scenemanagercreator.h"
//#include "../../inc/managers/transform/transform_manager_creator.h"


MoveModelCommand::MoveModelCommand(const double &dx, const double &dy, const double &dz, const std::size_t model_num) :
    _dx(dx), _dy(dy), _dz(dz), _model_num(model_num) { }


void MoveModelCommand::exec()
{
    Dot move(_dx, _dy, _dz);
    Dot scale(1, 1, 1);
    Dot spin(0, 0, 0);

    std::shared_ptr<Object> model = CreatorSceneManager().create_manager()->get_scene()->get_models().at(_model_num);
    //CreatorTransformManager().create_manager()->transform_object(model, move, scale, spin);
}

ScaleModelCommand::ScaleModelCommand(const double &kx, const double &ky, const double &kz, const std::size_t model_num) :
    _kx(kx), _ky(ky), _kz(kz), _model_num(model_num) { }

void ScaleModelCommand::exec()
{
    Dot move(0, 0, 0);
    Dot scale(_kx, _ky, _kz);
    Dot spin(0, 0, 0);

    std::shared_ptr<Object> model = CreatorSceneManager().create_manager()->get_scene()->get_models().at(_model_num);
    //CreatorTransformManager().create_manager()->transform_object(model, move, scale, spin);
}


SpinModelCommand::SpinModelCommand(const double &ox, const double &oy, const double &oz, const std::size_t model_num) :
        _ox(ox), _oy(oy), _oz(oz), _model_num(model_num) { }

void SpinModelCommand::exec()
{
    Dot move(0, 0, 0);
    Dot scale(1, 1, 1);
    Dot spin(_ox, _oy, _oz);

    std::shared_ptr<Object> model = CreatorSceneManager().create_manager()->get_scene()->get_models().at(_model_num);
    //CreatorTransformManager().create_manager()->transform_object(model, move, scale, spin);
}


TransformModelCommand::TransformModelCommand(const Dot &move, const Dot &scale, const Dot &spin, const std::size_t model_num) :
    _move(move), _scale(scale), _spin(spin), _model_num(model_num) { }

void TransformModelCommand::exec()
{
    std::shared_ptr<Object> model = CreatorSceneManager().create_manager()->get_scene()->get_models().at(_model_num);
    //CreatorTransformManager().create_manager()->transform_object(model, _move, _scale, _spin);
}

AddModelCommand::AddModelCommand(std::shared_ptr<Object> model) : _model(model) { }

void AddModelCommand::exec()
{
    CreatorSceneManager().create_manager()->get_scene()->add_model(_model);
}


RemoveModelCommand::RemoveModelCommand(const std::size_t model_num) : _model_num(model_num) { }

void RemoveModelCommand::exec()
{
    CreatorSceneManager().create_manager()->get_scene()->remove_model(_model_num);
}


CountModelCommand::CountModelCommand(const std::shared_ptr<std::size_t> &count) : _count(count) { }

void CountModelCommand::exec()
{
    (*_count) = CreatorSceneManager().create_manager()->get_scene()->get_models().size();
}

#include <iostream>

LoadModelCommand::LoadModelCommand(std::string file_name) : _file_name(file_name) { }

void LoadModelCommand::exec()
{
    auto moderator = LoadModelModeratorCreator().create_moderator();
    auto manager = CreatorLoadManager().create_manager(moderator);
    auto model = manager->load(_file_name);

    CreatorSceneManager().create_manager()->get_scene()->add_model(model);
}


ExportModelCommand::ExportModelCommand(std::string file_name) : _file_name(file_name) { }

void ExportModelCommand::exec() { }


