#ifndef CAMERACOMMAND_H
#define CAMERACOMMAND_H

#include <memory>
#include <cstddef>

#include "basecommand.h"

class CameraCommand : public BaseCommand {};

class AddCamera: public CameraCommand
{
public:
    AddCamera(const double x, const double y, const double z);

    virtual void execute() override;

private:
    double _x, _y, _z;
};


class DeleteCamera: public CameraCommand
{
public:
    DeleteCamera(const std::size_t index);

    virtual void execute() override;

private:
    std::size_t _index;
};


class MoveCamera: public CameraCommand
{
public:
    MoveCamera(const std::size_t index, const double dx, const double dy);

    virtual void execute() override;

private:
    double _dx, _dy;
    std::size_t _index;
};


class SetCamera: public CameraCommand
{
public:
    SetCamera(const std::size_t index);

    virtual void execute() override;

private:
    std::size_t _index;
};


class CountCamera: public CameraCommand
{
public:
    CountCamera(const std::shared_ptr<size_t> num);

    virtual void execute() override;

private:
    std::shared_ptr<size_t> _num;
};

#endif //CAMERACOMMAND_H
