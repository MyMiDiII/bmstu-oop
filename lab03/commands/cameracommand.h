#ifndef CAMERACOMMAND_H
#define CAMERACOMMAND_H

#include <memory>
#include <cstddef>

#include "basecommand.h"

class CameraCMD : public BaseCommand { };

class AddCameraCMD : public CameraCMD
{
public:
    AddCameraCMD(const double x, const double y, const double z);

    virtual void exec() override;

private:
    double _x, _y, _z;
};


class RemoveCameraCMD : public CameraCMD
{
public:
    RemoveCameraCMD(const std::size_t &viewer_num);

    virtual void exec() override;

private:
    std::size_t _viewer_num;
};


class MoveCameraCMD : public CameraCMD
{
public:
    MoveCameraCMD(const std::size_t &viewer_num, const double &dx, const double &dy);

    virtual void exec() override;

private:
    double _dx, _dy;
    std::size_t _viewer_num;
};


class SetCameraCMD : public CameraCMD
{
public:
    SetCameraCMD(const std::size_t &viewer_num);

    virtual void exec() override;

private:
    std::size_t _viewer_num;
};


class CountCameraCMD : public CameraCMD
{
public:
    CountCameraCMD(const std::shared_ptr<size_t> &count);

    virtual void exec() override;

private:
    std::shared_ptr<size_t> _count;
};

#endif //CAMERACOMMAND_H
