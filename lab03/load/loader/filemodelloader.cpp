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


std::shared_ptr<Object> ModelLoaderFile::load(std::shared_ptr<ModelBuilder> builder)
{
    builder->build();

    int count_dots;
    *_file >> count_dots;

    if (count_dots <= 0)
    {
        std::string msg = "wrong vertex num";
        throw SourceException(msg);
    }

    for (int i = 0; i < count_dots; i++)
    {
        double x, y, z;

        *_file >> x >> y >> z;
        builder->buildVertex(x, y, z);
    }

    int count_links;
    *_file >> count_links;

    if (count_links <= 0)
    {
        std::string msg = "wrong links num";
        throw SourceException(msg);
    }

    for (int i = 0; i < count_links; i++)
    {
        int dot1_num, dot2_num;

        *_file >> dot1_num >> dot2_num;

        if (dot1_num <= 0 or dot2_num <= 0 or
            dot1_num > count_dots or dot2_num > count_dots)
        {
            std::string msg = "wrong link data";
            throw SourceException(msg);
        }

        builder->buildLink(dot1_num, dot2_num);
    }

    return builder->get();
}

