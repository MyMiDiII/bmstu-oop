#include "modelbuilder.h"

void ModelBuilder::build()
{
    _model = std::make_shared<ModelStructure>();
}


void ModelBuilder::buildVertex(const double x, const double y, const double z)
{
    if (!isBuild()) {}

    Dot tmp(x, y, z);
    _model->add_dot(tmp);
}


void ModelBuilder::buildLink(const std::size_t vertex1Index, const std::size_t vertex2Index)
{
    if (!isBuild()) {}

    Link tmp(vertex1Index, vertex2Index);
    _model->add_link(tmp);
}


bool ModelBuilder::isBuild() const
{
    return nullptr != _model;
}

std::shared_ptr<Object> ModelBuilder::get()
{
    return std::make_shared<Model>(Model(_model));
}




