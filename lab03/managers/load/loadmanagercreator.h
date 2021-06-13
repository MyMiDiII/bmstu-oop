#ifndef LOAD_MANAGER_CREATOR_H
#define LOAD_MANAGER_CREATOR_H

#include <memory>

#include "loadmanager.h"


class CreatorLoadManager
{
public:
    std::shared_ptr<LoadManager> create_manager();
    std::shared_ptr<LoadManager> create_manager(const std::shared_ptr<AbstractLoadModerator> &loader);

private:
    void create_instance();

    std::shared_ptr<LoadManager> _manager;
};




#endif //LOAD_MANAGER_CREATOR_H
