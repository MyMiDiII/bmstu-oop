#include "model.h"

Model::Model(const Model &model)
{
    _modelStructure = model._modelStructure;
    _id = model._id;
}

void Model::transform(const Vertex &move, const Vertex &scale, const Vertex &rotate)
{
    _modelStructure->transform(move, scale, rotate);
}

void Model::accept(std::shared_ptr<Visitor> visitor)
{
    visitor->visit(*this);
}
