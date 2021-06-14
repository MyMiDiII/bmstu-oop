#ifndef LOADER_SCENE_FILE_H
#define LOADER_SCENE_FILE_H

#include "basesceneloader.h"

class SceneLoaderFile : public BaseLoaderScene
{
public:
    SceneLoaderFile();
    explicit SceneLoaderFile(std::shared_ptr<std::ifstream> &file_in);

    ~SceneLoaderFile() override = default;

    void open(std::string &file_name) override;
    void close() override;

    std::shared_ptr<Object> load(std::shared_ptr<SceneBuilder> builder) override;

protected:
    void load_models(std::shared_ptr<SceneBuilder> builder) override;
    void load_viewers(std::shared_ptr<SceneBuilder> builder) override;

    std::shared_ptr<std::ifstream> _file;
};


#endif //LOADER_SCENE_FILE_H
