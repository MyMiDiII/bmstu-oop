//
// Created by amunra23 on 22.05.2021.
//

#ifndef BASE_LOADER_H
#define BASE_LOADER_H

#include <string>
#include <fstream>

class BaseLoader
{
public:
    BaseLoader() = default;
    virtual ~BaseLoader() = default;

    virtual void open(std::string &file_name) = 0;
    virtual void close() = 0;
};

#endif //BASE_LOADER_H
