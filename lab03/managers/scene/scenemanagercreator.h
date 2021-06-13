#ifndef CREATOR_SCENE_MANAGER_H
#define CREATOR_SCENE_MANAGER_H

#include <memory>
#include "scenemanager.h"

class CreatorSceneManager
{
public:
    std::shared_ptr<SceneManager> create_manager();

private:
    void create_instance();

    std::shared_ptr<SceneManager> _manager;
};

#endif //CREATOR_SCENE_MANAGER_H
