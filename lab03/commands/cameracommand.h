//
// Created by amunra23 on 22.05.2021.
//

#ifndef VIEWER_COMMAND_H
#define VIEWER_COMMAND_H

#include "basecommand.h"
#include <memory>
#include <cstddef>


class AddViewerCommand : public ViewerBaseCommand
{
public:
    AddViewerCommand(const double x, const double y, const double z);

    virtual void exec() override;

private:
    double _x, _y, _z;
};


class RemoveViewerCommand : public ViewerBaseCommand
{
public:
    RemoveViewerCommand(const std::size_t &viewer_num);

    virtual void exec() override;

private:
    std::size_t _viewer_num;
};


class MoveViewerCommand : public ViewerBaseCommand
{
public:
    MoveViewerCommand(const std::size_t &viewer_num, const double &dx, const double &dy);

    virtual void exec() override;

private:
    double _dx, _dy;
    std::size_t _viewer_num;
};


class SetViewerCommand : public ViewerBaseCommand
{
public:
    SetViewerCommand(const std::size_t &viewer_num);

    virtual void exec() override;

private:
    std::size_t _viewer_num;
};


class CountViewerCommand : public ViewerBaseCommand
{
public:
    CountViewerCommand(const std::shared_ptr<size_t> &count);

    virtual void exec() override;

private:
    std::shared_ptr<size_t> _count;
};

#endif //VIEWER_COMMAND_H
