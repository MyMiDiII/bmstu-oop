#ifndef LOADMANAGER_H
#define LOADMANAGER_H

#include <memory>

#include "basemanager.h"
#include "model.h"
#include "baseloadmoderator.h"

class LoadManager : BaseManager
{
public:
    LoadManager();
    LoadManager(const LoadManager &manager) = delete;
    LoadManager &operator = (const LoadManager &manager) = delete;

    ~LoadManager() = default;

    virtual std::shared_ptr<Object> load(std::string &name);
    virtual void setLoader(std::shared_ptr<BaseLoadModerator> loader);

private:
    std::shared_ptr<BaseLoadModerator> _loader;
};


#endif // LOADMANAGER_H
