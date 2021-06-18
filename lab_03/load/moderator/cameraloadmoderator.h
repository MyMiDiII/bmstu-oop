#ifndef CAMERALOADMODERATOR_H
#define CAMERALOADMODERATOR_H

#include "baseloadmoderator.h"
#include "basecameraloader.h"

class CameraLoadModerator : public BaseLoadModerator
{
public:
    explicit CameraLoadModerator(std::shared_ptr<BaseCameraLoader> loader);
    ~CameraLoadModerator() = default;

    std::shared_ptr<Object> load(std::string &fileName) override;

private:
    std::shared_ptr<CameraBuilder> _builder;
    std::shared_ptr<BaseCameraLoader> _loader;
};

#endif // CAMERALOADMODERATOR_H
