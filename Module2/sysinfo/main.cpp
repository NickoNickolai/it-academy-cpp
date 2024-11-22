#include <iostream>

#include "sysinfo.h"

int main()
{
    SysInfo info;
    std::cout << info.get_os_string() << std::endl;
    std::cout << info.get_compiler_string() << std::endl;

    return 0;
}
