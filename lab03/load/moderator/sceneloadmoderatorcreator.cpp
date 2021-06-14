#include "sceneloadmoderatorcreator.h"
#include "filesceneloader.h"

std::shared_ptr<LoadSceneModerator> LoadSceneModeratorCreator::create_moderator()
{
    if (nullptr == _moderator)
        create_instance();

    return _moderator;
}

std::shared_ptr<LoadSceneModerator> LoadSceneModeratorCreator::create_moderator(const std::shared_ptr<BaseLoaderScene> &loader)
{
    if (nullptr == _moderator)
    {
        create_instance();
    }

    _moderator->set_loader(loader);

    return _moderator;
}

void LoadSceneModeratorCreator::create_instance()
{
    static std::shared_ptr<LoadSceneModerator> moderator;

    if (!moderator)
    {
        std::shared_ptr<BaseLoaderScene> loader;
        loader = std::shared_ptr<BaseLoaderScene>(new SceneLoaderFile);
        moderator = std::make_shared<LoadSceneModerator>(loader);
    }

    _moderator = moderator;
}


