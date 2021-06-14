#include "sceneloadmoderator.h"
#include "exceptions.h"


SceneLoadModerator::SceneLoadModerator(std::shared_ptr<BaseSceneLoader> loader) :
    _builder(new SceneBuilder)
{
    _loader = loader;
}

std::shared_ptr<Object> SceneLoadModerator::load(std::string &fileName)
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

    std::shared_ptr<Object> scene;

    try
    {
        scene = _loader->load(_builder);
    }
    catch (std::exception &error)
    {
        _loader->close();
        std::string msg = "Error : Read model";
        throw SourceException(msg);
    }

    _loader->close();

    return scene;
}





