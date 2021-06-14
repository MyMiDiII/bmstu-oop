#ifndef LOADMANAGERCREATOR_H
#define LOADMANAGERCREATOR_H

#include <memory>

#include "loadmanager.h"


class LoadManagerCreator
{
public:
    std::shared_ptr<LoadManager> createManager();
    std::shared_ptr<LoadManager> createManager(const std::shared_ptr<BaseLoadModerator> &loader);

private:
    void createInstance();

    std::shared_ptr<LoadManager> _manager;
};

#endif //LOADMANAGERCREATOR_H
