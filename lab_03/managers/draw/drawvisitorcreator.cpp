#include "drawvisitorcreator.h"

std::shared_ptr<DrawVisitor> DrawVisitorCreator::createVisitor() {
    if (nullptr == _visitor)
        createInstance();

    return _visitor;
}


void DrawVisitorCreator::createInstance()
{
    static std::shared_ptr<DrawVisitor> visitor(new DrawVisitor());
    _visitor = visitor;
}
