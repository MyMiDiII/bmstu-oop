#ifndef MODELCOMMAND_H
#define MODELCOMMAND_H

#include <cstddef>
#include <memory>

#include "basecommand.h"
#include "object.h"

class ModelCMD : public BaseCommand { };

class MoveModelCMD : public ModelCMD
{
public:
    MoveModelCMD(const double &dx, const double &dy, const double &dz, const std::size_t model_num);

    virtual void exec() override;

private:
    double _dx, _dy, _dz;
    std::size_t _model_num;
};


class ScaleModelCMD : public ModelCMD
{
public:
    ScaleModelCMD(const double &kx, const double &ky, const double &kz, const std::size_t model_num);

    virtual void exec() override;

private:
    double _kx, _ky, _kz;
    std::size_t _model_num;
};


class SpinModelCMD : public ModelCMD
{
public:
    SpinModelCMD(const double &ox, const double &oy, const double &oz, const std::size_t model_num);

    virtual void exec() override;

private:
    double _ox, _oy, _oz;
    std::size_t _model_num;
};


class TransformModelCMD : public ModelCMD
{
public:
    TransformModelCMD(const Dot &move, const Dot &scale, const Dot &spin, const std::size_t model_num);

    virtual void exec() override;

private:
    Dot _move, _scale, _spin;
    std::size_t _model_num;
};


class AddModelCMD : public ModelCMD
{
public:
    AddModelCMD(std::shared_ptr<Object> model);

    virtual void exec() override;

private:
    std::shared_ptr<Object> _model;
};



class RemoveModelCMD : public ModelCMD
{
public:
    RemoveModelCMD(std::size_t model_num);

    virtual void exec() override;

private:
    std::size_t _model_num;
};


class CountModelCMD : public ModelCMD
{
public:
    CountModelCMD(const std::shared_ptr<size_t> &count);

    virtual void exec() override;

private:
    std::shared_ptr<size_t> _count;
};


class LoadModelCMD : public ModelCMD
{
public:
    LoadModelCMD(std::string file_name);

    virtual void exec() override;

private:
    std::string _file_name;
};


class ExportModelCMD : public ModelCMD
{
public:
    ExportModelCMD(std::string file_name);

    virtual void exec() override;

private:
    std::string _file_name;
};

#endif //MODELCOMMAND_H
