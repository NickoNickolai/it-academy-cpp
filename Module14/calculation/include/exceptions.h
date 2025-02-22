#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>
#include <string>

namespace exc
{
class BaseException
{
public:
    BaseException() : BaseException("custom exception") {}
    BaseException(const std::string &what) : _what(what) {}

    // Получение пояснительной строки с ошибкой
    std::string what() const { return _what; }

private:
    std::string _what;
};

class InvalidLogArgument : public BaseException
{
public:
    InvalidLogArgument() : InvalidLogArgument("invalid log argument") {}
    InvalidLogArgument(const std::string &what) : BaseException(what) {}
};

class InvalidRadusArgument: public std::exception
{
public:
    InvalidRadusArgument() : InvalidRadusArgument("invalid radius argument") {}
#ifdef _MSC_VER
    InvalidRadusArgument(const std::string &what) : std::exception(what.c_str()) {}
#else
    InvalidRadusArgument(const std::string &what) : _what(what) {}

    // Получение пояснительной строки с ошибкой
    const char *what() const noexcept override { return _what.c_str(); }

private:
    std::string _what;
#endif
};

class InvalidOperation: public BaseException
{
public:
    InvalidOperation() : InvalidOperation("invalid operation") {}
    InvalidOperation(const std::string &what) : BaseException(what) {}
};
}

#endif // EXCEPTIONS_H
