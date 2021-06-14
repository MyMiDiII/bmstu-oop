#ifndef DRAW_MANAGER_H
#define DRAW_MANAGER_H

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

    void set_viewer(std::shared_ptr<Viewer> viewer);
    void set_drawer(std::shared_ptr<BaseDrawer> drawer);

    void visit(const Model &model) override;
    void visit(const Viewer &viewer) override {};
    void visit(const Composite &composite) override {};

private:
    Dot get_dot_proection(const Dot &dot);

    std::shared_ptr<Viewer> _viewer;
    std::shared_ptr<BaseDrawer> _drawer;

};

#endif //DRAW_MANAGER_H
