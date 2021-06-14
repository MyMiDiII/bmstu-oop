#ifndef BASELOADMODERATOR_H
#define BASELOADMODERATOR_H

#include <memory>

#include "basebuilder.h"
#include "baseloader.h"

class Model;
class BaseLoader;

class BaseLoadModerator
{
public:
    BaseLoadModerator() = default;
    ~BaseLoadModerator() = default;

    virtual std::shared_ptr<Object> load(std::string &name) = 0;
    virtual void setLoader(std::shared_ptr<BaseLoader> loader);

protected:
    std::shared_ptr<BaseLoader> _loader;
};

#endif // BASELOADMODERATOR_H
