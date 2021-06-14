#include "transformmanagercreator.h"


std::shared_ptr<TransformManager> CreatorTransformManager::create_manager()
{
    if (nullptr == _manager)
        create_instance();

    return _manager;
}

void CreatorTransformManager::create_instance()
{
    static std::shared_ptr<TransformManager> manager(new TransformManager());
    _manager = manager;
}
