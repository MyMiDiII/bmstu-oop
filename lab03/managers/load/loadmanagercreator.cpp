//
// Created by amunra23 on 20.05.2021.
//

#include "loadmanagercreator.h"

void CreatorLoadManager::create_instance()
{
    static std::shared_ptr<LoadManager> manager(new LoadManager());

    _manager = manager;
}


std::shared_ptr<LoadManager> CreatorLoadManager::create_manager()
{
    if (nullptr == _manager)
    {
        create_instance();
    }

    return _manager;
}

std::shared_ptr<LoadManager> CreatorLoadManager::create_manager(const std::shared_ptr <AbstractLoadModerator> &loader)
{
    if (nullptr == _manager)
    {
        create_instance();
    }

    _manager->set_loader(loader);

    return _manager;
}

