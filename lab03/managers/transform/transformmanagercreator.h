#ifndef TRANSFORM_MANAGER_CREATOR_H
#define TRANSFORM_MANAGER_CREATOR_H

#include "transformmanager.h"


class CreatorTransformManager
{
public:
    std::shared_ptr<TransformManager> create_manager();

private:
    void create_instance();

    std::shared_ptr<TransformManager> _manager;
};


#endif //TRANSFORM_MANAGER_CREATOR_H
