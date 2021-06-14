#ifndef SCENELOADMODERATOR_H
#define SCENELOADMODERATOR_H

#include "baseloadmoderator.h"
#include "basesceneloader.h"
#include "baseloader.h"
#include "scenebuilder.h"

class SceneLoadModerator : public BaseLoadModerator
{
public:
    explicit SceneLoadModerator(std::shared_ptr<BaseSceneLoader> loader);

    ~SceneLoadModerator() = default;

    std::shared_ptr<Object> load(std::string &fileName) override;

private:
    std::shared_ptr<SceneBuilder> _builder;
    std::shared_ptr<BaseSceneLoader> _loader;
};

#endif // SCENELOADMODERATOR_H
