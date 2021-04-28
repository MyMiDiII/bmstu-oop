#ifndef BASEEXCEPTION_H
#define BASEEXCEPTION_H

#include <exception>
#include <string>

using str = std::string;

class BaseException : public std::exception
{
public:
    BaseException(const str &time, const str &fileName,
                  const uint line, const str &className,
                  const str &methodName, const str &info);

    virtual const char *what() const noexcept;
protected:
    str errInfo;
};

#include "base_exception.hpp"

#endif // BASEEXCEPTON_H
