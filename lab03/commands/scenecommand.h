#ifndef SCENECOMMAND_H
#define SCENECOMMAND_H

#include <memory>
#include "basecommand.h"
#include "basedrawer.h"

class SceneCMD : public BaseCommand { };

class DrawSceneCMD : public SceneCMD
{
public:
    DrawSceneCMD(std::shared_ptr<AbstractDrawer> drawer);

    virtual void exec() override;

private:
    std::shared_ptr<AbstractDrawer> _drawer;
};


class LoadSceneCMD : public SceneCMD
{
public:
    LoadSceneCMD(std::string file_name);

    virtual void exec() override;

private:
    std::string _file_name;
};

#endif //SCENECOMMAND_H
