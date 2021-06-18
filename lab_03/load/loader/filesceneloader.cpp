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


void FileSceneLoader::open(std::string &file_name)
{
    if (!_file)
    {
        std::string msg = "Error : File open";
        throw SourceException(msg);
    }

    _file->open(file_name);

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


std::shared_ptr<Scene> FileSceneLoader::load(std::shared_ptr<SceneBuilder> builder)
{
    builder->build();

    loadModels(builder);
    loadCameras(builder);

    return builder->get();
}

void FileSceneLoader::loadModels(std::shared_ptr<SceneBuilder> builder)
{
    int num;

    *_file >> num;

    auto modBuilder = std::make_shared<ModelBuilder>();

    for (int i = 0; i < num; i++)
        builder->buildObject(FileModelLoader(_file).load(modBuilder));
}

void FileSceneLoader::loadCameras(std::shared_ptr<SceneBuilder> builder)
{
    int num;

    *_file >> num;

    auto camBuilder = std::make_shared<CameraBuilder>();

    for (int i = 0; i < num; i++)
        builder->buildObject(FileCameraLoader(_file).load(camBuilder));
}



