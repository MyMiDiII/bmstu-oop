#ifndef BUILDER_SCENE_H
#define BUILDER_SCENE_H

#include "scene.h"
#include "basebuilder.h"

class BuilderScene : public BaseBuilder
{
public:
    BuilderScene() = default;
    ~BuilderScene() = default;

    void build() override;
    void build_model(const std::shared_ptr<Object> &object);
    void build_viewer(const std::shared_ptr<Viewer> &viewer);

    bool is_build() const override;

    std::shared_ptr<Object> get() override;

private:
    std::shared_ptr<Scene> _scene_ptr;
};


#endif //BUILDER_SCENE_H
