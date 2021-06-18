#include "sceneloadmoderatorcreator.h"
#include "filesceneloader.h"

std::shared_ptr<SceneLoadModerator> SceneLoadModeratorCreator::createModerator()
{
    if (nullptr == _moderator)
        createInstance();

    return _moderator;
}

std::shared_ptr<SceneLoadModerator> SceneLoadModeratorCreator::createModerator(
        const std::shared_ptr<BaseSceneLoader> &loader)
{
    if (nullptr == _moderator)
        createInstance();

    _moderator->setLoader(loader);

    return _moderator;
}

void SceneLoadModeratorCreator::createInstance()
{
    static std::shared_ptr<SceneLoadModerator> moderator;

    if (!moderator)
    {
        std::shared_ptr<BaseSceneLoader> loader;
        loader = std::shared_ptr<BaseSceneLoader>(new FileSceneLoader);
        moderator = std::make_shared<SceneLoadModerator>(loader);
    }

    _moderator = moderator;
}


