#include "loadmanager.h"
#include "sceneloadmoderatorcreator.h"
#include "modelloadmoderator.h"

LoadManager::LoadManager()
{
    _loader = SceneLoadModeratorCreator().createModerator();
}

std::shared_ptr<Object> LoadManager::load(std::string &name)
{
    return _loader->load(name);
}

void LoadManager::set_loader(std::shared_ptr<BaseLoadModerator> loader)
{
    _loader = loader;
}

