#ifndef SCENE_H
#define SCENE_H

#include "object.h"
#include <vector>
//#include "camera.h"

class Scene : public Object
{
public:
    Scene();
    ~Scene() override = default;

    std::vector<std::shared_ptr<Object>> getModels();
    std::vector<std::shared_ptr<Camera>> getCameras();
    std::shared_ptr<Composite> getComposite();

    void addModel(const std::shared_ptr<Object> &model);
    void deleteModel(const std::size_t index);

    void addCamera(const std::shared_ptr<Camera> &camera);
    void deleteCamera(const std::size_t index);

protected:
    std::vector<std::shared_ptr<Camera>> _cameras;
    std::shared_ptr<Composite> _models;

    void accept(std::shared_ptr<Visitor> visitor) override {};
    void transform(const Vertex &move, const Vertex &scale,
                   const Vertex &rotate) override {};
};

#endif //SCENE_H
