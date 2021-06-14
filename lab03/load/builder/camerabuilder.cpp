#include "camerabuilder.h"

void BuilderViewer::build()
{
    _viewer_ptr = std::make_shared<Viewer>();
}

void BuilderViewer::build_position(const double x, const double y, const double z)
{

}

bool BuilderViewer::is_build() const
{
    return nullptr != _viewer_ptr;
}

std::shared_ptr<Object> BuilderViewer::get()
{
    return _viewer_ptr;
}

