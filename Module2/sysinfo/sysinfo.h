#ifndef SYSINFO_H
#define SYSINFO_H

#include <string>

class SysInfo
{
public:
    std::string get_os_string();
    std::string get_compiler_string();
};

#endif // SYSINFO_H
