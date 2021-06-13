//
// Created by amunra23 on 22.05.2021.
//

#ifndef BASE_LOADER_MODEL_H
#define BASE_LOADER_MODEL_H

#include "baseloader.h"
#include "modelbuilder.h"

class BaseLoaderModel : public BaseLoader
{
public:
    virtual std::shared_ptr<Object> load(std::shared_ptr<BuilderModel> builder) = 0;
};

#endif //BASE_LOADER_MODEL_H
