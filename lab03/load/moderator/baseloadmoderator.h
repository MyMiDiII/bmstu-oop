#ifndef BASELOADMODERATOR_H
#define BASELOADMODERATOR_H

#include <memory>

#include "baseloader.h"

class BaseLoadModerator
{
public:
    BaseLoadModerator() = default;
    ~BaseLoadModerator() = default;

    virtual std::shared_ptr<Object> load(std::string &fileName) = 0;
    virtual void setLoader(std::shared_ptr<BaseLoader> loader);

protected:
    std::shared_ptr<BaseLoader> _loader;
};

#endif // BASELOADMODERATOR_H
