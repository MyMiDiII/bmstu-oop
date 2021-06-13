#include "model.h"

Model::Model(const Model &model)
{
    _modelStructure = model._modelStructure;
}

//std::shared_ptr<ModelStructure> Model::get_modelStructure() const {
//    return _modelStructure;
//}


void Model::transform(const Dot &move, const Dot &scale, const Dot &spin)
{
    _modelStructure->transform(move, scale, spin);
}


//std::unique_ptr<Model> Model::clone()
//{
//    return std::make_unique<Model>(*this);
//}


void Model::accept(std::shared_ptr<Visitor> visitor)
{
    visitor->visit(*this);
}
