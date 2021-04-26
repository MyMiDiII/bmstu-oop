#ifndef BASEEXCEPTON_H
#define BASEEXCEPTON_H

#include <exception>
#include <string>

// Изменить имя (добавит i)

using str = std::string;

class BaseExcepton : public std::exception
{
public:
    BaseExcepton(const str &time, const str &fileName,
                 const uint line, const str &className,
                 const str &methodName, const str &info);

    virtual const char *what() const noexcept;
protected:
    str errInfo;
};

#include "base_excepton.hpp"

#endif // BASEEXCEPTON_H
