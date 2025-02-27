#include "logger.h"
#include <iostream>
#include <iomanip>

void Logger::log(const std::string &msg)
{
    std::cout << "[DEBUG]: " << msg << std::endl;
}

void Logger::msg(const std::string &name, const std::string &msg)
{
    std::cout << std::setw(10) << name << ": " << msg << std::endl;
}

void Logger::str(const std::string &msg)
{
    std::cout << msg << std::endl;
}
