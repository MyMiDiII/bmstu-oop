#ifndef DRAW_MANAGER_CREATOR_H
#define DRAW_MANAGER_CREATOR_H

#include "drawmanager.h"

class CreatorDrawManager
{
public:
    std::shared_ptr<DrawManager> create_manager();

private:
    void create_instance();

    std::shared_ptr<DrawManager> _manager;
};

#endif //DRAW_MANAGER_CREATOR_H
