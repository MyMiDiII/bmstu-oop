#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include "base_excepton.h"

class ExpiredException : public BaseExcepton
{
public:
    ExpiredException(const str &time, const str &fileName,
                     const uint line, const str &className,
                     const str &methodName,
                     const str &info = "Expired weak pointer!")
    : BaseExcepton(time, fileName, line, className, methodName, info)
    {};
};


class OutOfRangeException : public BaseExcepton
{
public:
    OutOfRangeException(const str &time, const str &fileName,
                     const uint line, const str &className,
                     const str &methodName,
                     const str &info = "Index is out of range!")
    : BaseExcepton(time, fileName, line, className, methodName, info)
    {};
};

#endif // EXCEPTIONS_H
