#ifndef COMPOSITE_H
#define COMPOSITE_H

#include "object.h"
#include "scene.h"
#include "drawvisitor.h"

class Composite : public Object
{
    friend void DrawVisitor::visit(const Composite &composite);

public:
    Composite() = default;
    explicit Composite(std::shared_ptr<Object> &element);
    explicit Composite(const std::vector<std::shared_ptr<Object>> &vector);

    bool add(const std::shared_ptr<Object> &element) override;
    bool remove(const Iterator &iter) override;

    bool isVisible() override;
    bool isComposite() override;

    virtual void transform(const Vertex &move, const Vertex &scale, const Vertex &rotate) override;
    void accept(std::shared_ptr<Visitor> visitor) override;

    Iterator begin() override;
    Iterator end() override;

private:
    std::vector<std::shared_ptr<Object>> _elements;
};

#endif //COMPOSITE_H
