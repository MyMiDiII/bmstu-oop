//
// Created by amunra23 on 22.05.2021.
//

#ifndef LOAD_MODEL_MODERATOR_CREATOR_H
#define LOAD_MODEL_MODERATOR_CREATOR_H

#include "modelloadmoderator.h"

class LoadModelModeratorCreator
{
public:
    std::shared_ptr<LoadModelModerator> create_moderator();
    std::shared_ptr<LoadModelModerator> create_moderator(const std::shared_ptr<BaseLoaderModel> &loader);

private:
    void create_instance();

    std::shared_ptr<LoadModelModerator> _moderator;
};

#endif //LOAD_MODEL_MODERATOR_CREATOR_H
