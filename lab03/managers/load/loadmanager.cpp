#include "loadmanager.h"
#include "cameraloadmoderatorcreator.h"
#include "modelloadmoderator.h"

#include <QDebug>

std::shared_ptr<Object> LoadManager::load(std::string &name)
{
    return _loader->load(name);
}

void LoadManager::setLoader(std::shared_ptr<BaseLoadModerator> loader)
{
    _loader = loader;
}

