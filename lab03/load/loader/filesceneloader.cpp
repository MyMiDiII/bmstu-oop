#include "filesceneloader.h"
#include "filecameraloader.h"
#include "filemodelloader.h"
#include "exceptions.h"

FileSceneLoader::FileSceneLoader()
{
    _file = std::make_shared<std::ifstream>();
}

FileSceneLoader::FileSceneLoader(std::shared_ptr<std::ifstream> &file)
{
    _file = file;
}


void FileSceneLoader::open(std::string &fileName)
{
    if (!_file)
    {
        std::string msg = "Error : File open";
        throw SourceException(msg);
    }

    _file->open(fileName);

    if (!_file)
    {
        std::string msg = "Error : File open";
        throw SourceException(msg);
    }
}


void FileSceneLoader::close()
{
    if (!_file)
    {
        std::string msg = "Error : File open";
        throw SourceException(msg);
    }

    _file->close();
}


std::shared_ptr<Object> FileSceneLoader::load(std::shared_ptr<SceneBuilder> builder)
{
    builder->build();

    loadModels(builder);
    loadCameras(builder);

    return builder->get();
}

void FileSceneLoader::loadModels(std::shared_ptr<SceneBuilder> builder)
{
    int modelsNum;

    *_file >> modelsNum;

    auto modelBuilder = std::make_shared<ModelBuilder>();

    for (int i = 0; i < modelsNum; i++)
    {
        builder->buildModel(FileModelLoader(_file).load(modelBuilder));
    }
}

void FileSceneLoader::loadCameras(std::shared_ptr<SceneBuilder> builder)
{
    int camerasNum;

    *_file >> camerasNum;

    auto cameraBuilder = std::make_shared<CameraBuilder>();

    for (int i = 0; i < camerasNum; i++)
    {
        builder->buildCamera(std::dynamic_pointer_cast<Viewer>(
                             FileCameraLoader(_file).load(cameraBuilder)));
    }
}



