//
// Created by amunra23 on 22.05.2021.
//

#ifndef BASE_COMMAND_H
#define BASE_COMMAND_H


class BaseCommand
{
public:
    BaseCommand() = default;

    virtual ~BaseCommand() = default;

    virtual void exec() = 0;
};


class ViewerBaseCommand : public BaseCommand { };

class SceneBaseCommand : public BaseCommand { };

class ModelBaseCommand : public BaseCommand { };

#endif //BASE_COMMAND_H
