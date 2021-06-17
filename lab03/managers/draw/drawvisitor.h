#ifndef DRAWVISITOR_H
#define DRAWVISITOR_H

#include <memory>
#include "visitor.h"
#include "basedrawer.h"

class DrawVisitor : public Visitor
{
public:
    DrawVisitor() = default;

    void setCamera(std::shared_ptr<Camera> camera);
    void setDrawer(std::shared_ptr<BaseDrawer> drawer);

    void visit(const Model &model) override;
    void visit(const Camera &camera) override {};
    void visit(const Composite &composite) override;

    Vertex getProjection(const Vertex &vertex);

private:
    std::shared_ptr<Camera> _camera;
    std::shared_ptr<BaseDrawer> _drawer;
};

#endif // DRAWVISITOR_H
