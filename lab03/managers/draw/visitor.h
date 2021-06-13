#ifndef VISITOR_H
#define VISITOR_H

class Model;
class Viewer;
class Composite;

class Visitor
{
public:
    Visitor() = default;
    ~Visitor() = default;

    virtual void visit(const Model &model) = 0;
    virtual void visit(const Viewer &viewer) = 0;
    virtual void visit(const Composite &composite) = 0;
};

#endif //VISITOR_H
