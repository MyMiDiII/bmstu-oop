#ifndef MODELBUILDER_H
#define MODELBUILDER_H

#include "modelstructure.h"
#include "model.h"
#include "basebuilder.h"

class BuilderModel : public BaseBuilder
{
public:
    BuilderModel() = default;
    ~BuilderModel() = default;

    void build() override;
    void build_dot(const double &x, const double &y, const double &z);
    void build_link(const std::size_t &dot1_num, const std::size_t dot2_num);

    bool is_build() const override;

    std::shared_ptr<Object> get() override;

private:
    std::shared_ptr<ModelStructure> _model_ptr;
};

#endif //BUILDER_MODEL_H
