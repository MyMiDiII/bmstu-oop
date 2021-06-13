#include "baseloadmoderator.h"

void AbstractLoadModerator::set_loader(std::shared_ptr<BaseLoader> loader)
{
    _loader = loader;
}

