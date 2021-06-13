#include "filemodelloader.h"
#include "exceptions.h"
#include "modelbuilder.h"


ModelLoaderFile::ModelLoaderFile()
{
    _file = std::make_shared<std::ifstream>();
}


ModelLoaderFile::ModelLoaderFile(std::shared_ptr<std::ifstream> &file_in)
{
    _file = file_in;
}


void ModelLoaderFile::open(std::string &file_name)
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


void ModelLoaderFile::close()
{
    if (!_file)
    {
        std::string msg = "Error : File open";
        throw SourceException(msg);
    }

    _file->close();
}


std::shared_ptr<Object> ModelLoaderFile::load(std::shared_ptr<BuilderModel> builder)
{
    builder->build();

    // Dots

    int count_dots;
    *_file >> count_dots;

    for (int i = 0; i < count_dots; i++)
    {
        double x, y, z;

        *_file >> x >> y >> z;
        builder->build_dot(x, y, z);
    }


    // Links

    int count_links;
    *_file >> count_links;

    for (int i = 0; i < count_links; i++)
    {
        int dot1_num, dot2_num;

        *_file >> dot1_num >> dot2_num;
        builder->build_link(dot1_num, dot2_num);
    }

    return builder->get();
}

