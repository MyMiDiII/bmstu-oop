#ifndef BASEMODELLOADER_H
#define BASEMODELLOADER_H

#include "baseloader.h"
#include "modelbuilder.h"

class BaseModelLoader : public BaseLoader
{
public:
    virtual std::shared_ptr<Model> load(std::shared_ptr<ModelBuilder> builder) = 0;
};

#endif // BASEMODELLOADER_H
