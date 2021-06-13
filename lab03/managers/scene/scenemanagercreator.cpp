#include "scenemanagercreator.h"

std::shared_ptr<SceneManager> CreatorSceneManager::create_manager() {
    if (nullptr == _manager)
    {
        create_instance();
    }

    return _manager;
}


void CreatorSceneManager::create_instance()
{
    static std::shared_ptr<SceneManager> manager(new SceneManager());

    _manager = manager;
}
