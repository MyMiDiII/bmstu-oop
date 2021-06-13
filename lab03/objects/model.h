#ifndef MODEL_H
#define MODEL_H

#include <memory>
#include <utility>

#include "object.h"
#include "vertex.h"
#include "link.h"
#include "modelstructure.h"
#include "visitor.h"
#include "drawmanager.h"

class Model : public VisibleObject
{
    friend void DrawManager::visit(const Model &model);

public:

    Model() : _modelStructure(new ModelStructure) { }
    explicit Model(const std::shared_ptr<ModelStructure> &modelStructure) : _modelStructure(modelStructure) {};
    Model(const Model &model);

    ~Model() override = default;

    //std::shared_ptr<ModelStructure> get_modelStructure() const;

    void transform(const Dot &move, const Dot &scale, const Dot &spin) override;

    void accept(std::shared_ptr<Visitor> visitor) override;

protected:
    std::shared_ptr<ModelStructure> _modelStructure;
};


#endif //MODEL_H
