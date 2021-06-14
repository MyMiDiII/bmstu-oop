#ifndef SCENE_H
#define SCENE_H

#include <vector>

#include "camera.h"
#include "composite.h"

class Scene : public Object
{
public:
    Scene() : _models(new Composite) {};
    ~Scene() override = default;

    std::vector<std::shared_ptr<Object>> get_models();
    std::vector<std::shared_ptr<Camera>> get_viewers();
    std::shared_ptr<Composite> get_composite();

    void add_model(const std::shared_ptr<Object> &model);
    void remove_model(const std::size_t index);

    void add_viewer(const std::shared_ptr<Camera> &viewer);
    void remove_viewer(const std::size_t index);

protected:
    std::vector<std::shared_ptr<Camera>> _viewers;
    std::shared_ptr<Composite> _models;

    void accept(std::shared_ptr<Visitor> visitor) override {};
    void transform(const Vertex &move, const Vertex &scale, const Vertex &rotate) override {};
};

#endif //SCENE_H
