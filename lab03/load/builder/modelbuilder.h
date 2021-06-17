#ifndef MODELBUILDER_H
#define MODELBUILDER_H

#include "modelstructure.h"
#include "model.h"
#include "basebuilder.h"

class ModelBuilder : public BaseBuilder
{
public:
    ModelBuilder() = default;
    ~ModelBuilder() = default;

    void build() override;
    void buildVertex(const double x, const double y, const double z);
    void buildLink(const std::size_t vertex1Index, const std::size_t vertex2Index);
    bool isBuild() const override;

    std::shared_ptr<Model> get();

private:
    std::shared_ptr<ModelStructure> _model;
};

#endif //BUILDER_MODEL_H
