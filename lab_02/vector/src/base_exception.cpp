#ifndef BASEEXCEPTION_HPP
#define BASEEXCEPTION_HPP

#include "base_exception.h"

using namespace std;

BaseException::BaseException(
        const str &time, const str &fileName,
        const uint line, const str &className,
        const str &methodName, const str &info = "Something went wrong!")
{
    errInfo = "\nTime:   " + time +
              "File:   " + fileName +
              "\nLine:   " + to_string(line) +
              "\nClass:  " + className +
              "\nMethod: " + methodName +
              "\nInfo:   " + info + "\n";
}

const char *BaseException::what() const noexcept
{
    return errInfo.c_str();
}

#endif
