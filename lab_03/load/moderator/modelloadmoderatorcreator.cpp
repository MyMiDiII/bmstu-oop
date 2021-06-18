#include "modelloadmoderatorcreator.h"
#include "filemodelloader.h"

std::shared_ptr<ModelLoadModerator> ModelLoadModeratorCreator::createModerator()
{
    if (nullptr == _moderator)
        createInstance();

    return _moderator;
}

std::shared_ptr<ModelLoadModerator> ModelLoadModeratorCreator::createModerator(
        const std::shared_ptr<BaseModelLoader> &loader)
{
    if (nullptr == _moderator)
        createInstance();

    _moderator->setLoader(loader);

    return _moderator;
}

void ModelLoadModeratorCreator::createInstance()
{
    static std::shared_ptr<ModelLoadModerator> moderator;

    if (!moderator)
    {
        std::shared_ptr<BaseModelLoader> loader;
        loader = std::shared_ptr<BaseModelLoader>(new FileModelLoader);
        moderator = std::make_shared<ModelLoadModerator>(loader);
    }

    _moderator = moderator;
}

