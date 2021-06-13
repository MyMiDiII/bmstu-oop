#include "drawmanagercreator.h"


std::shared_ptr<DrawManager> CreatorDrawManager::create_manager() {
    if (nullptr == _manager)
    {
        create_instance();
    }

    return _manager;
}


void CreatorDrawManager::create_instance() {
    static std::shared_ptr<DrawManager> manager(new DrawManager());

    _manager = manager;
}
