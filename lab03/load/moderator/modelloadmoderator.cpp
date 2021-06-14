#include "modelloadmoderator.h"

#include "exceptions.h"


LoadModelModerator::LoadModelModerator(std::shared_ptr<BaseLoaderModel> loader) : _builder(new BuilderModel)
{
    _loader = loader;
}


std::shared_ptr<Object> LoadModelModerator::load(std::string &file_name)
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

    std::shared_ptr<Object> model;

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




