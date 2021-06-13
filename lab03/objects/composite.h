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

    bool is_visible() override;
    bool is_composite() override;

    virtual void transform(const Dot &move, const Dot &scale, const Dot &spin) override;
    void accept(std::shared_ptr<Visitor> visitor) override;

    Iterator begin() override;
    Iterator end() override;

    std::size_t get_size() const;
    std::vector<std::shared_ptr<Object>> &get_objects();

private:
    std::vector<std::shared_ptr<Object>> _elements;
};

#endif //COMPOSITE_H
