#ifndef COMPOSITE_H
#define COMPOSITE_H

#include "object.h"
#include "visitor.h"

class Composite : public Object
{
public:
    Composite() = default;
    explicit Composite(std::shared_ptr<Object> &element);
    explicit Composite(const std::vector<std::shared_ptr<Object>> &vector);

    bool add(const std::shared_ptr<Object> &element) override;
    bool remove(const Iterator &iter) override;

    bool isVisible() override;
    bool isComposite() override;

    virtual void transform(const Vertex &move, const Vertex &scale, const Vertex &spin) override;
    void accept(std::shared_ptr<Visitor> visitor) override;

    Iterator begin() override;
    Iterator end() override;

    // delete
    std::size_t getSize() const;
    std::vector<std::shared_ptr<Object>> &getObjects();

private:
    std::vector<std::shared_ptr<Object>> _elements;
};

#endif //COMPOSITE_H
