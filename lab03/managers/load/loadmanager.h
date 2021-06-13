//
// Created by amunra23 on 19.05.2021.
//

#ifndef LOAD_MANAGER_H
#define LOAD_MANAGER_H

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
    virtual void set_loader(std::shared_ptr<AbstractLoadModerator> loader);

private:
    std::shared_ptr<AbstractLoadModerator> _loader;
};


#endif //LOAD_MANAGER_H
