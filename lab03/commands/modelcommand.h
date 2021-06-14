#ifndef MODELCOMMAND_H
#define MODELCOMMAND_H

#include <cstddef>
#include <memory>

#include "basecommand.h"
#include "object.h"

class ModelCommand : public BaseCommand { };

class MoveModel : public ModelCommand
{
public:
    MoveModel(const double &dx, const double &dy, const double &dz, const std::size_t index);

    virtual void execute() override;

private:
    double _dx, _dy, _dz;
    std::size_t _index;
};


class ScaleModel : public ModelCommand
{
public:
    ScaleModel(const double &kx, const double &ky, const double &kz, const std::size_t index);

    virtual void execute() override;

private:
    double _kx, _ky, _kz;
    std::size_t _index;
};


class RotateModel : public ModelCommand
{
public:
    RotateModel(const double &ox, const double &oy, const double &oz, const std::size_t index);

    virtual void execute() override;

private:
    double _ox, _oy, _oz;
    std::size_t _index;
};


class TransformModel : public ModelCommand
{
public:
    TransformModel(const Vertex &move, const Vertex &scale, const Vertex &rotate, const std::size_t index);

    virtual void execute() override;

private:
    Vertex _move, _scale, _rotate;
    std::size_t _index;
};


class AddModel : public ModelCommand
{
public:
    AddModel(std::shared_ptr<Object> model);

    virtual void execute() override;

private:
    std::shared_ptr<Object> _model;
};



class DeleteModel : public ModelCommand
{
public:
    DeleteModel(const std::size_t index);

    virtual void execute() override;

private:
    std::size_t _index;
};


class CountModel : public ModelCommand
{
public:
    CountModel(const std::shared_ptr<size_t> &num);

    virtual void execute() override;

private:
    std::shared_ptr<size_t> _num;
};


class LoadModel : public ModelCommand
{
public:
    LoadModel(std::string fileName);

    virtual void execute() override;

private:
    std::string _fileName;
};

#endif //MODELCOMMAND_H
