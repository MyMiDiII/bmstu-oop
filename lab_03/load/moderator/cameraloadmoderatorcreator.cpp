#include "cameraloadmoderatorcreator.h"
#include "filecameraloader.h"

std::shared_ptr<CameraLoadModerator> CameraLoadModeratorCreator::createModerator()
{
    if (nullptr == _moderator)
        createInstance();

    return _moderator;
}

std::shared_ptr<CameraLoadModerator> CameraLoadModeratorCreator::createModerator(
        const std::shared_ptr<BaseCameraLoader> &loader)
{
    if (nullptr == _moderator)
    {
        createInstance();
    }

    _moderator->setLoader(loader);

    return _moderator;
}

void CameraLoadModeratorCreator::createInstance()
{
    static std::shared_ptr<CameraLoadModerator> moderator;

    if (!moderator)
    {
        std::shared_ptr<BaseCameraLoader> loader;
        loader = std::shared_ptr<BaseCameraLoader>(new FileCameraLoader);
        moderator = std::make_shared<CameraLoadModerator>(loader);
    }

    _moderator = moderator;
}


