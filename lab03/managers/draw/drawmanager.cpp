#include "drawmanager.h"
#include "model.h"
#include "camera.h"

void DrawManager::setVisitor(std::shared_ptr<Visitor> visitor)
{
    _visitor = visitor;
}

void DrawManager::drawScene(std::shared_ptr<Scene> scene)
{
    scene->accept(_visitor);
}
