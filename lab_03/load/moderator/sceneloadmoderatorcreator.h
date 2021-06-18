#ifndef SCENELOADMODERATORCREATOR_H
#define SCENELOADMODERATORCREATOR_H

#include "sceneloadmoderator.h"

class SceneLoadModeratorCreator
{
public:
    std::shared_ptr<SceneLoadModerator> createModerator();
    std::shared_ptr<SceneLoadModerator> createModerator(
            const std::shared_ptr<BaseSceneLoader> &loader);

private:
    void createInstance();

    std::shared_ptr<SceneLoadModerator> _moderator;
};


#endif //SCENELOADMODERATORCREATOR_H
