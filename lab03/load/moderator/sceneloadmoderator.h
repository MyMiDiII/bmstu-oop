#ifndef LOAD_MODEL_MODERATOR_H
#define LOAD_MODEL_MODERATOR_H

#include "baseloadmoderator.h"
#include "basesceneloader.h"
#include "baseloader.h"
#include "scenebuilder.h"

class LoadSceneModerator : public AbstractLoadModerator
{
public:
    explicit LoadSceneModerator(std::shared_ptr<BaseLoaderScene> loader);

    ~LoadSceneModerator() = default;

    std::shared_ptr<Object> load(std::string &file_name) override;

private:
    std::shared_ptr<BuilderScene> _builder;
    std::shared_ptr<BaseLoaderScene> _loader;
};

#endif //LOAD_MODEL_MODERATOR_H
