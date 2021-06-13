//
// Created by amunra23 on 19.05.2021.
//

#include "loadmanager.h"
//#include "../../../inc/managers/load/load_scene_moderator_creator.h"
#include "modelloadmoderator.h"

LoadManager::LoadManager()
{
    //_loader = LoadSceneModeratorCreator().create_moderator();
}

std::shared_ptr<Object> LoadManager::load(std::string &name)
{
    return _loader->load(name);
}

void LoadManager::set_loader(std::shared_ptr<AbstractLoadModerator> loader)
{
    _loader = loader;
}

