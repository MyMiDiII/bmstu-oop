#ifndef FILEMODELLOADER_H
#define FILEMODELLOADER_H

#include "basemodelloader.h"

class ModelLoaderFile : public BaseLoaderModel
{
public:
    ModelLoaderFile();
    explicit ModelLoaderFile(std::shared_ptr<std::ifstream> &file_in);

    ~ModelLoaderFile() override = default;

    void open(std::string &file_name) override;
    void close() override;

    std::shared_ptr<Object> load(std::shared_ptr<ModelBuilder> builder) override;

protected:
    std::shared_ptr<std::ifstream> _file;
};

#endif //FILEMODELLOADER_H
