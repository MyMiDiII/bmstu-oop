//
// Created by amunra23 on 22.05.2021.
//

#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <string>
#include <exception>


class BaseException : public std::exception
{
public:
    explicit BaseException(std::string &msg) : _msg(msg) { }

    const char *what() const noexcept override
    {
        return "Something has happened";
    }

    const std::string &get_info() const noexcept
    {
        return _msg;
    }

protected:
    std::string _msg;
};


class ViewerException : public BaseException
{
public:
    explicit ViewerException(std::string &msg) : BaseException(msg) { }

    const char *what() const noexcept override
    {
        return "Viewer isn't added";
    }
};


class SourceException : public BaseException
{
public:
    explicit SourceException(std::string &msg) : BaseException(msg) { }

    const char *what() const noexcept override
    {
        return "Load mistake : doesn't exist or problem occurred";
    }
};


class ModelException : public BaseException
{
public:
    explicit ModelException(std::string &msg) : BaseException(msg) { }

    const char *what() const noexcept override
    {
        return "Can't build model";
    }
};

#endif //EXCEPTIONS_H
