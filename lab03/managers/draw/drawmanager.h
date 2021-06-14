#ifndef DRAWMANAGER_H
#define DRAWMANAGER_H

#include "basemanager.h"
#include "vertex.h"
#include "composite.h"
#include "object.h"
#include "camera.h"

#include "basedrawer.h"
#include "visitor.h"

class DrawManager : public BaseManager, public Visitor
{
public:
    DrawManager() = default;
    DrawManager(const DrawManager &manager) = delete;
    DrawManager &operator = (const DrawManager &manager) = delete;

    ~DrawManager() = default;

    void setCamera(std::shared_ptr<Camera> camera);
    void setDrawer(std::shared_ptr<BaseDrawer> drawer);

    void visit(const Model &model) override;
    void visit(const Camera &camera) override {};
    void visit(const Composite &composite) override {};

private:
    Vertex getProjection(const Vertex &dot);

    std::shared_ptr<Camera> _camera;
    std::shared_ptr<BaseDrawer> _drawer;

};

#endif //DRAWMANAGER_H
