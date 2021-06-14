#ifndef OBJECT_H
#define OBJECT_H

#include <memory>
#include <vector>

#include "visitor.h"
#include "vertex.h"

class Object;

using Iterator = std::vector<std::shared_ptr<Object>>::iterator;

class Object
{
public:
    Object() = default;
    virtual ~Object() = default;

    virtual bool add(const std::shared_ptr<Object> &) { return false; };
    virtual bool remove(const Iterator &) { return false; };

    virtual bool isVisible() { return false; };
    virtual bool isComposite() { return  false; };

    virtual void accept(std::shared_ptr<Visitor> visitor) = 0;
    virtual void transform(const Vertex &move, const Vertex &scale, const Vertex &rotate) = 0;

    virtual Iterator begin() { return Iterator(); };
    virtual Iterator end() { return Iterator(); };
};


class VisibleObject : public Object
{
public:
    VisibleObject() = default;
    ~VisibleObject() override = default;

    bool isVisible() override { return true; }
};


class InvisibleObject : public Object
{
public:
    InvisibleObject() = default;
    ~InvisibleObject() override = default;

    bool isVisible() override { return false; }
};

#endif //OBJECT_H
