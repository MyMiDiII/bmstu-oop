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

class EmptyVectorException : public BaseException
{
public:
    EmptyVectorException(const str &time, const str &fileName,
                         const uint line, const str &className,
                         const str &methodName,
                         const str &info = "Operation with an empty vector!")
    : BaseException(time, fileName, line, className, methodName, info)
    {};
};

class NotEqualSizesException : public BaseException
{
public:
    NotEqualSizesException(const str &time, const str &fileName,
             const uint line, const str &className,
             const str &methodName,
             const str &info = "Operation with vectors of different sizes!")
    : BaseException(time, fileName, line, className, methodName, info)
    {};
};

class Not3DException : public BaseException
{
public:
    Not3DException(const str &time, const str &fileName,
             const uint line, const str &className,
             const str &methodName,
             const str &info = "Vector product with non 3D-vectors")
    : BaseException(time, fileName, line, className, methodName, info)
    {};
};

class DivisionByZeroException: public BaseException
{
public:
    DivisionByZeroException(const str &time, const str &fileName,
             const uint line, const str &className,
             const str &methodName,
             const str &info = "Division by zero!")
    : BaseException(time, fileName, line, className, methodName, info)
    {};
};
#endif // EXCEPTIONS_H
