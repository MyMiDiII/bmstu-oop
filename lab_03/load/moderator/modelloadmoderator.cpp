#include "modelloadmoderator.h"

#include "exceptions.h"
#include <QDebug>


ModelLoadModerator::ModelLoadModerator(std::shared_ptr<BaseModelLoader> loader) :
    _builder(new ModelBuilder)
{
    _loader = loader;
}


std::shared_ptr<Object> ModelLoadModerator::load(std::string &file_name)
{
    try
    {
        _loader->open(file_name);
    }
    catch (SourceException &error)
    {
        std::string msg = "Error : Open file";
        throw SourceException(msg);
    }

    std::shared_ptr<Model> model;

    try
    {
        model = _loader->load(_builder);
    }
    catch (std::exception &error)
    {
        _loader->close();
        std::string msg = "Error : Read model";
        throw SourceException(msg);
    }

    _loader->close();

    return model;
}




