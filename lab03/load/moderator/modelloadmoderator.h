#ifndef LOAD_MODEL_MODERATOR_H
#define LOAD_MODEL_MODERATOR_H

#include "baseloadmoderator.h"
#include "basemodelloader.h"
#include "baseloader.h"
#include "modelbuilder.h"

class LoadModelModerator : public AbstractLoadModerator
{
public:
    explicit LoadModelModerator(std::shared_ptr<BaseLoaderModel> loader);

    ~LoadModelModerator() = default;

    std::shared_ptr<Object> load(std::string &file_name) override;

private:
    std::shared_ptr<ModelBuilder> _builder;
    std::shared_ptr<BaseLoaderModel> _loader;
};

#endif //LOAD_MODEL_MODERATOR_H
