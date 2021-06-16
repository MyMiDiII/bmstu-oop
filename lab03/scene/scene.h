#ifndef SCENE_H
#define SCENE_H

#include <vector>

#include "object.h"
#include "composite.h"
#include "drawvisitor.h"

class Scene : public Object
{
    friend void DrawVisitor::visit(const Scene &scene);
public:
    Scene();
    ~Scene() override = default;

    std::shared_ptr<Composite> getModels();
    std::shared_ptr<Composite> getCameras();

    void addModel(const std::shared_ptr<Object> &model);
    void deleteModel(const std::size_t index);

    void addCamera(const std::shared_ptr<Object> &camera);
    void deleteCamera(const std::size_t index);

    void accept(std::shared_ptr<Visitor> visitor) override;
    void transform(const Vertex &move, const Vertex &scale,
                   const Vertex &rotate) override {};

protected:
    std::shared_ptr<Composite> _models;
    std::shared_ptr<Composite> _cameras;

};

#endif //SCENE_H
