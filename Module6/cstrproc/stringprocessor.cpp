#include "stringprocessor.h"
#include <iostream>
#include <cstring>

void StringProcessor::process()
{
    std::cout << "Enter a string: ";
    std::getline(std::cin, _s);

    auto str = new char[_s.size() + 1] { 0 };
    memcpy(str, _s.c_str(), _s.size());
    reverse_string(str);

    std::cout << "Reversed string: " << str << std::endl;
    delete[] str;
}

void StringProcessor::reverse_string(char *str)
{
    int n = _s.size();
    for(int i = 0; i < n / 2; ++i)
    {
        std::swap(str[i], str[n - 1 - i]);
    }
}
