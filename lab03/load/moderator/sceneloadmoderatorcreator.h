#ifndef LOAD_SCENE_MODERATOR_CREATOR_H
#define LOAD_SCENE_MODERATOR_CREATOR_H

#include "sceneloadmoderator.h"

class LoadSceneModeratorCreator
{
public:
    std::shared_ptr<LoadSceneModerator> create_moderator();
    std::shared_ptr<LoadSceneModerator> create_moderator(const std::shared_ptr<BaseLoaderScene> &loader);

private:
    void create_instance();

    std::shared_ptr<LoadSceneModerator> _moderator;
};


#endif //LOAD_SCENE_MODERATOR_CREATOR_H
