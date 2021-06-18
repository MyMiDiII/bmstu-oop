#ifndef CAMERALOADMODERATORCREATOR_H
#define CAMERALOADMODERATORCREATOR_H

#include "cameraloadmoderator.h"

class CameraLoadModeratorCreator
{
public:
    std::shared_ptr<CameraLoadModerator> createModerator();
    std::shared_ptr<CameraLoadModerator> createModerator(
            const std::shared_ptr<BaseCameraLoader> &loader);

private:
    void createInstance();

    std::shared_ptr<CameraLoadModerator> _moderator;
};


#endif // CAMERALOADMODERATORCREATOR_H
