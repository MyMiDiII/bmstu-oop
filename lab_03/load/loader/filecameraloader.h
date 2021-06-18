#ifndef FILECAMERALOADER_H
#define FILECAMERALOADER_H

#include "basecameraloader.h"

class FileCameraLoader : public BaseCameraLoader
{
public:
    FileCameraLoader();
    explicit FileCameraLoader(std::shared_ptr<std::ifstream> &file);

    ~FileCameraLoader() override = default;

    void open(std::string &fileName) override;
    void close() override;

    std::shared_ptr<Camera> load(std::shared_ptr<CameraBuilder> builder) override;

protected:
    std::shared_ptr<std::ifstream> _file;
};

#endif // FILECAMERALOADER_H
