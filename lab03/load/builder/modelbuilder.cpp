#include "modelbuilder.h"

void BuilderModel::build()
{
    _model_ptr = std::make_shared<ModelStructure>();
}


void BuilderModel::build_dot(const double &x, const double &y, const double &z)
{
    if (!is_build()) {}

    Dot tmp(x, y, z);
    _model_ptr->add_dot(tmp);
}


void BuilderModel::build_link(const size_t &dot1_num, const std::size_t dot2_num)
{
    if (!is_build()) {}

    Link tmp(dot1_num, dot2_num);
    _model_ptr->add_link(tmp);
}


bool BuilderModel::is_build() const
{
    return nullptr != _model_ptr;
}

std::shared_ptr<Object> BuilderModel::get() {
    return std::make_shared<Model>(Model(_model_ptr));
}




