#ifndef SCENELOADMODERATOR_H
#define SCENELOADMODERATOR_H

#include "basesceneloader.h"
#include "scenebuilder.h"

class SceneLoadModerator
{
public:
    explicit SceneLoadModerator(std::shared_ptr<BaseSceneLoader> loader);

    ~SceneLoadModerator() = default;

    std::shared_ptr<Scene> load(std::string &fileName);
    virtual void setLoader(std::shared_ptr<BaseSceneLoader> loader);

private:
    std::shared_ptr<SceneBuilder> _builder;
    std::shared_ptr<BaseSceneLoader> _loader;
};

#endif //SCENELOADMODERATOR_H
