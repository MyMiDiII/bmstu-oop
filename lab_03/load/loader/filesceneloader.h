#ifndef FILESCENELOADER_H
#define FILESCENELOADER_H

#include "basesceneloader.h"

class FileSceneLoader : public BaseSceneLoader
{
public:
    FileSceneLoader();
    explicit FileSceneLoader(std::shared_ptr<std::ifstream> &fileIn);
    ~FileSceneLoader() = default;

    void open(std::string &fileName) override;
    void close() override;

    std::shared_ptr<Scene> load(std::shared_ptr<SceneBuilder> builder) override;

protected:
    void loadModels(std::shared_ptr<SceneBuilder> builder) override;
    void loadCameras(std::shared_ptr<SceneBuilder> builder) override;

    std::shared_ptr<std::ifstream> _file;
};


#endif //FILESCENELOADER_H
