#ifndef SCENEBUILDER_H
#define SCENEBUILDER_H

#include "scene.h"
#include "basebuilder.h"

class SceneBuilder : public BaseBuilder
{
public:
    SceneBuilder() = default;
    ~SceneBuilder() = default;

    void build() override;
    void buildObject(const std::shared_ptr<Object> &object);
    bool isBuild() const override;

    std::shared_ptr<Scene> get();

private:
    std::shared_ptr<Scene> _scene;
};


#endif //SCENEBUILDER_H
