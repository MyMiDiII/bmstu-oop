#ifndef MODELLOADMODERATOR_H
#define MODELLOADMODERATOR_H

#include "baseloadmoderator.h"
#include "basemodelloader.h"
#include "baseloader.h"
#include "modelbuilder.h"

class ModelLoadModerator : public BaseLoadModerator
{
public:
    explicit ModelLoadModerator(std::shared_ptr<BaseModelLoader> loader);
    ~ModelLoadModerator() = default;

    std::shared_ptr<Object> load(std::string &fileName) override;

private:
    std::shared_ptr<ModelBuilder> _builder;
    std::shared_ptr<BaseModelLoader> _loader;
};

#endif // MODELLOADMODERATOR_H
