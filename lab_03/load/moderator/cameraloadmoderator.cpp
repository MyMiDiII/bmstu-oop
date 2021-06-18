#include "cameraloadmoderator.h"
#include "exceptions.h"


CameraLoadModerator::CameraLoadModerator(std::shared_ptr<BaseCameraLoader> loader) :
    _builder(new CameraBuilder)
{
    _loader = loader;
}

std::shared_ptr<Object> CameraLoadModerator::load(std::string &fileName)
{
    try
    {
        _loader->open(fileName);
    }
    catch (SourceException &error)
    {
        std::string msg = "Error : Open file";
        throw SourceException(msg);
    }

    std::shared_ptr<Camera> camera;

    try
    {
        camera = _loader->load(_builder);
    }
    catch (std::exception &error)
    {
        _loader->close();
        std::string msg = "Error : Read model";
        throw SourceException(msg);
    }

    _loader->close();

    return camera;
}





