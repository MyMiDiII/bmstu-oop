#ifndef BASEMODELLOADER_H
#define BASEMODELLOADER_H

#include "baseloader.h"
#include "modelbuilder.h"

class BaseLoaderModel : public BaseLoader
{
public:
    virtual std::shared_ptr<Object> load(std::shared_ptr<ModelBuilder> builder) = 0;
};

#endif //BASELOADER_MODEL_H
