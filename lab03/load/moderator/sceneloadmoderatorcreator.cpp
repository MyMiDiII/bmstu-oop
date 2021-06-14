#include "sceneloadmoderatorcreator.h"
#include "filesceneloader.h"

std::shared_ptr<LoadSceneModerator> LoadSceneModeratorCreator::create_moderator()
{
    if (nullptr == _moderator)
        create_instance();

    return _moderator;
}

std::shared_ptr<LoadSceneModerator> LoadSceneModeratorCreator::create_moderator(
        const std::shared_ptr<BaseSceneLoader> &loader)
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
        std::shared_ptr<BaseSceneLoader> loader;
        loader = std::shared_ptr<BaseSceneLoader>(new FileSceneLoader);
        moderator = std::make_shared<LoadSceneModerator>(loader);
    }

    _moderator = moderator;
}


