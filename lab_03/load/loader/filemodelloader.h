#ifndef FILEMODELLOADER_H
#define FILEMODELLOADER_H

#include "basemodelloader.h"

class FileModelLoader : public BaseModelLoader
{
public:
    FileModelLoader();
    explicit FileModelLoader(std::shared_ptr<std::ifstream> &file);

    ~FileModelLoader() override = default;

    void open(std::string &fileName) override;
    void close() override;

    std::shared_ptr<Model> load(std::shared_ptr<ModelBuilder> builder) override;

protected:
    std::shared_ptr<std::ifstream> _file;
};

#endif //FILEMODELLOADER_H
