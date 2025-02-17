#ifndef LOGGER_H
#define LOGGER_H

#include <string>

class Logger
{
public:
    // Debug лог
    static void log(const std::string &msg);

    // Основное игровое сообщение
    static void msg(const std::string &name, const std::string &msg);

    // Вспомогательное игровое сообщение
    static void str(const std::string &msg);

private:
    Logger() = delete;
    Logger(const Logger &) = delete;
    Logger &operator=(const Logger &) = delete;
    Logger(Logger &&) = delete;
    Logger &operator=(Logger &&) = delete;
};

#endif // LOGGER_H
