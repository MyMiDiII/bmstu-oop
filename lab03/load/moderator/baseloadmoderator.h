#ifndef ABSTRACT_LOAD_MODERATOR_H
#define ABSTRACT_LOAD_MODERATOR_H

#include <memory>

#include "basebuilder.h"
#include "baseloader.h"

class Model;
class BaseLoader;

class AbstractLoadModerator
{
public:
    AbstractLoadModerator() = default;
    ~AbstractLoadModerator() = default;

    virtual std::shared_ptr<Object> load(std::string &name) = 0;
    virtual void set_loader(std::shared_ptr<BaseLoader> loader);

protected:
    std::shared_ptr<BaseLoader> _loader;
};

#endif //ABSTRACT_LOAD_MODERATOR_H
