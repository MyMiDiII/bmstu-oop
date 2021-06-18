#ifndef MODELLOADMODERATORCREATOR_H
#define MODELLOADMODERATORCREATOR_H

#include "modelloadmoderator.h"

class ModelLoadModeratorCreator
{
public:
    std::shared_ptr<ModelLoadModerator> createModerator();
    std::shared_ptr<ModelLoadModerator> createModerator(
            const std::shared_ptr<BaseModelLoader> &loader);

private:
    void createInstance();

    std::shared_ptr<ModelLoadModerator> _moderator;
};

#endif // MODELLOADMODERATORCREATOR_H
