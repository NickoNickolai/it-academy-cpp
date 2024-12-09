#ifndef PRINTER_H
#define PRINTER_H

#include <string>
#include <vector>
#include <memory>

class Printer
{
public:
    // Вывод в консоль значений различных входных типов
    static void print(int value);
    static void print(float value);
    static void print(const std::string &value);
    static void print(char *value, int n);
    static void print(int *value, int n);
    static void print(const std::vector<int> &value);
    static void print(std::shared_ptr<int> value);
    static void print(std::unique_ptr<double> &value);
};

#endif // PRINTER_H
