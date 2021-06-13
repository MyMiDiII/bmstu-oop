#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include "basemanager.h"
#include "scene.h"


class SceneManager : public BaseManager
{
public:
    SceneManager();
    SceneManager(const SceneManager &scene) = delete;
    SceneManager &operator = (const SceneManager &scene)  = delete;

    ~SceneManager() = default;

    std::shared_ptr<Scene> get_scene() const;
    std::shared_ptr<Viewer> get_viewer() const;

    void set_scene(std::shared_ptr<Scene> scene);
    void set_viewer(const std::size_t &viewer_index);

private:
    std::shared_ptr<Viewer> _viewer;
    std::shared_ptr<Scene> _scene;
};


#endif //SCENE_MANAGER_H
