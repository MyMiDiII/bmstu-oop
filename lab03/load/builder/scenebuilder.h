#ifndef BUILDER_SCENE_H
#define BUILDER_SCENE_H

#include "scene.h"
#include "basebuilder.h"

class SceneBuilder : public BaseBuilder
{
public:
    SceneBuilder() = default;
    ~SceneBuilder() = default;

    void build() override;
    void buildModel(const std::shared_ptr<Object> &object);
    void buildCamera(const std::shared_ptr<Camera> &viewer);
    bool isBuild() const override;

    std::shared_ptr<Object> get() override;

private:
    std::shared_ptr<Scene> _scene;
};


#endif //BUILDER_SCENE_H
