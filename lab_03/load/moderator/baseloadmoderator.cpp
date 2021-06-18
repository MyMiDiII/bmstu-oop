#include "baseloadmoderator.h"

void BaseLoadModerator::setLoader(std::shared_ptr<BaseLoader> loader)
{
    _loader = loader;
}
