#include "filesceneloader.h"
#include "filecameraloader.h"
#include "filemodelloader.h"
#include "exceptions.h"

SceneLoaderFile::SceneLoaderFile()
{
    _file = std::make_shared<std::ifstream>();
}

SceneLoaderFile::SceneLoaderFile(std::shared_ptr<std::ifstream> &file_in)
{
    _file = file_in;
}


void SceneLoaderFile::open(std::string &file_name)
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


void SceneLoaderFile::close()
{
    if (!_file)
    {
        std::string msg = "Error : File open";
        throw SourceException(msg);
    }

    _file->close();
}


std::shared_ptr<Object> SceneLoaderFile::load(std::shared_ptr<BuilderScene> builder)
{
    builder->build();

    load_models(builder);
    load_viewers(builder);

    return builder->get();
}

void SceneLoaderFile::load_models(std::shared_ptr<BuilderScene> builder)
{
    int count_models;

    *_file >> count_models;

    auto model_builder = std::make_shared<BuilderModel>();

    for (int i = 0; i < count_models; i++)
    {
        builder->build_model(ModelLoaderFile(_file).load(model_builder));
    }
}

void SceneLoaderFile::load_viewers(std::shared_ptr<BuilderScene> builder)
{
    int count_viewers;

    *_file >> count_viewers;

    auto viewer_builder = std::make_shared<BuilderViewer>();

    for (int i = 0; i < count_viewers; i++)
    {
        builder->build_viewer(std::dynamic_pointer_cast<Viewer>(ViewerLoaderFile(_file).load(viewer_builder)));
    }
}



