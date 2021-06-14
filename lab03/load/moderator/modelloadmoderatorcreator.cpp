#include "modelloadmoderatorcreator.h"
#include "filemodelloader.h"

std::shared_ptr<LoadModelModerator> LoadModelModeratorCreator::create_moderator()
{
    if (nullptr == _moderator)
    {
        create_instance();
    }

    return _moderator;
}

std::shared_ptr<LoadModelModerator> LoadModelModeratorCreator::create_moderator(
        const std::shared_ptr<BaseModelLoader> &loader)
{
    if (nullptr == _moderator)
    {
        create_instance();
    }

    _moderator->set_loader(loader);

    return _moderator;
}

void LoadModelModeratorCreator::create_instance()
{
    static std::shared_ptr<LoadModelModerator> moderator;

    if (!moderator)
    {
        std::shared_ptr<BaseModelLoader> loader;
        loader = std::shared_ptr<BaseModelLoader>(new FileModelLoader);
        moderator = std::make_shared<LoadModelModerator>(loader);
    }

    _moderator = moderator;
}

