#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include "base_exception.h"

class ExpiredException : public BaseException
{
public:
    ExpiredException(const str &time, const str &fileName,
                     const uint line, const str &className,
                     const str &methodName,
                     const str &info = "Expired weak pointer!")
    : BaseException(time, fileName, line, className, methodName, info)
    {};
};


class OutOfRangeException : public BaseException
{
public:
    OutOfRangeException(const str &time, const str &fileName,
                     const uint line, const str &className,
                     const str &methodName,
                     const str &info = "Index is out of range!")
    : BaseException(time, fileName, line, className, methodName, info)
    {};
};

class MemoryException : public BaseException
{
public:
    MemoryException(const str &time, const str &fileName,
                     const uint line, const str &className,
                     const str &methodName,
                     const str &info = "Memory allocation error!")
    : BaseException(time, fileName, line, className, methodName, info)
    {};
};
#endif // EXCEPTIONS_H
