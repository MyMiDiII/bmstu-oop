#include "filecameraloader.h"
#include "exceptions.h"

ViewerLoaderFile::ViewerLoaderFile()
{
    _file = std::make_shared<std::ifstream>();
}

ViewerLoaderFile::ViewerLoaderFile(std::shared_ptr<std::ifstream> &file_in)
{
    _file = file_in;
}

void ViewerLoaderFile::open(std::string &file_name)
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

void ViewerLoaderFile::close()
{
    if (!_file)
    {
        std::string msg = "Error : File open";
        throw SourceException(msg);
    }

    _file->close();
}

std::shared_ptr<Object> ViewerLoaderFile::load(std::shared_ptr<BuilderViewer> builder)
{
    builder->build();

    double x, y, z;

    *_file >> x >> y >> z;

    builder->build_position(x, y, z);

    return builder->get();
}



