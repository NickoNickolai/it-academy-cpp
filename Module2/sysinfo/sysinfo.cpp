#include "sysinfo.h"

#include <sstream>
#include <iostream>

#ifdef USE_BOOST
#include <boost/predef.h>
#endif

#if unix | __HAIKU__
#include <sys/utsname.h>
#elif _WIN32
#include <windows.h>
#endif

std::string SysInfo::get_os_string()
{
#if unix | __HAIKU__
    std::string sysname = "";
    std::string nodename = "";
    std::string version = "";
    std::string release = "";
    std::string machine = "";

    struct utsname buf;

    if( !uname( &buf ) )
    {
        sysname = std::string( buf.sysname );
        nodename = std::string( buf.nodename );
        release = std::string( buf.release );
        version = std::string( buf.version );
        machine = std::string( buf.machine );
    }

#elif _WIN32
    OSVERSIONINFOEXA vi;
    memset( &vi, 0, sizeof( vi ) );
    vi.dwOSVersionInfoSize = sizeof( vi );
    GetVersionExA( ( OSVERSIONINFOA * )&vi );
#endif

    std::stringstream info;
    info << "Operating system: ";
#ifdef USE_BOOST
#if BOOST_OS_UNIX | BOOST_OS_HAIKU
    info << sysname << " " << nodename << " " << release << " " << machine;
#elif BOOST_OS_WINDOWS
    info << "Microsoft Windows " << vi.dwMajorVersion << "." << vi.dwMinorVersion << "." << vi.dwBuildNumber;
#elif BOOST_OS_MACOS
    info << "macOS " << __APPLE__;
#else
    info << "unknown";
#endif
#else
#if unix | __HAIKU__
    info << sysname << " " << nodename << " " << release << " " << machine;
#elif _WIN32
    info << "Microsoft Windows " << vi.dwMajorVersion << "." << vi.dwMinorVersion << "." << vi.dwBuildNumber;
#elif __APPLE__
    info << "macOS " << __APPLE__;
#else
    info << "unknown";
#endif
#endif
    return info.str();
}

std::string SysInfo::get_compiler_string()
{
    std::stringstream info;
    info << "Compiler: ";
#ifdef USE_BOOST
#if BOOST_COMP_GNUC
    info << "GCC " << __VERSION__;
#elif BOOST_COMP_CLANG
    info << "Clang " << __clang_major__ << "." << __clang_minor__ << "." << __clang_patchlevel__;
#elif BOOST_COMP_MSVC
    info << "MSVC " << _MSC_VER;
#elif BOOST_COMP_BORLAND
    info << "Borland " << BOOST_COMP_BORLAND;
#elif BOOST_COMP_NVCC
    info << "NVCC " << __CUDACC_VER_MAJOR__ << "." << __CUDACC_VER_MINOR__ << "." << __CUDACC_VER_BUILD__;
#else
    info << "unknown";
#endif
#else
#if _MSC_VER
    info << "MSVC " << _MSC_VER;
#elif __BORLANDC__
    info << "Borland " << __BORLANDC__;
#elif __NVCC__
    info << "NVCC " << __CUDACC_VER_MAJOR__ << "." << __CUDACC_VER_MINOR__ << "." << __CUDACC_VER_BUILD__;
#elif __clang__
    info << "Clang " << __clang_major__ << "." << __clang_minor__ << "." << __clang_patchlevel__;
#elif __GNUC__
    info << "GCC " << __VERSION__;
#else
    compiler = "unknown";
#endif
#endif
    return info.str();
}
