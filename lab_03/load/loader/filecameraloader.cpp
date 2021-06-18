#include "filecameraloader.h"
#include "exceptions.h"

FileCameraLoader::FileCameraLoader()
{
    _file = std::make_shared<std::ifstream>();
}

FileCameraLoader::FileCameraLoader(std::shared_ptr<std::ifstream> &file)
{
    _file = file;
}

void FileCameraLoader::open(std::string &fileName)
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

void FileCameraLoader::close()
{
    if (!_file)
    {
        std::string msg = "Error : File open";
        throw SourceException(msg);
    }

    _file->close();
}

std::shared_ptr<Camera> FileCameraLoader::load(std::shared_ptr<CameraBuilder> builder)
{
    builder->build();

    double x, y, z;

    *_file >> x >> y >> z;

    builder->buildLocation(x, y, z);

    return builder->get();
}



