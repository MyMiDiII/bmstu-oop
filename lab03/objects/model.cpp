#include "model.h"

Model::Model(const Model &model)
{
    _modelStructure = model._modelStructure;
}

void Model::transform(const Dot &move, const Dot &scale, const Dot &spin)
{
    _modelStructure->transform(move, scale, spin);
}

void Model::accept(std::shared_ptr<Visitor> visitor)
{
    visitor->visit(*this);
}
