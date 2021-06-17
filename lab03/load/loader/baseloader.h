#ifndef BASELOADER_H
#define BASELOADER_H

#include <string>
#include <fstream>
#include <memory>

#include "object.h"

class BaseLoader
{
public:
    BaseLoader() = default;
    virtual ~BaseLoader() = default;

    virtual void open(std::string &fileName) = 0;
    virtual void close() = 0;
};

#endif //BASE_LOADER_H
