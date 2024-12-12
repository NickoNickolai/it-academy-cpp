#include "printer.h"
#include <cstring>

int main()
{
    const char A[] = {1, 1, 0, 0, 1, 0, 1, 0};
    {
        int value = 42;
        Printer::print(value);
    }
    {
        float value = 0.5f;
        Printer::print(value);
    }
    {
        std::string value = "Hello world!";
        Printer::print(value);
    }
    {
        int n = 8;
        auto value = new char[n];
        memcpy(value, A, n * sizeof(char));
        Printer::print(value, n);
        delete[] value;
    }
    {
        int n = 2;
        auto value = new int[n];
        memcpy(value, A, n * sizeof(int));
        Printer::print(value, n);
        delete[] value;
    }
    {
        std::vector<int> value{ 1, 3, 5, 7, 9 };
        Printer::print(value);
    }
    {
        auto value = std::make_shared<int>(42);
        Printer::print(value);
    }
    {
        auto value = std::make_unique<double>(0.5);
        Printer::print(value);
    }

    return 0;
}
