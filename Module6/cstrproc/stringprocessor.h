#ifndef STRINGPROCESSOR_H
#define STRINGPROCESSOR_H

#include <string>

class StringProcessor
{
public:
    StringProcessor() = default;

    // Запуск обработки
    void process();

    // Переворачивание строки
    void reverse_string(char *str);

private:
    std::string _s;
};

#endif // STRINGPROCESSOR_H
