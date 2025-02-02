#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>
#include <string>

namespace exc
{
class InvalidLogArgument
{
public:
    InvalidLogArgument() : InvalidLogArgument("invalid log argument") {}
    InvalidLogArgument(const std::string &what) : _what(what) {}

    // Получение пояснительной строки с ошибкой
    std::string what() const { return _what; }

private:
    std::string _what;
};

class InvalidRadusArgument: public std::exception
{
public:
    InvalidRadusArgument() : InvalidRadusArgument("invalid radius argument") {}
#if _MSC_VER
    InvalidRadusArgument(const std::string &what) : std::exception(what.c_str()) {}
#else
    InvalidRadusArgument(const std::string &what) : _what(what) {}

    // Получение пояснительной строки с ошибкой
    const char *what() const noexcept override { return _what.c_str(); }

private:
    std::string _what;
#endif
};
}

#endif // EXCEPTIONS_H
