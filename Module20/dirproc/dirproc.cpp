#include "dirproc.h"
#include <iostream>
#include <filesystem>
#include <regex>

DirProc::DirProc()
    : _filesCount(0)
{}

void DirProc::input()
{
    std::cout << "Enter directory name: ";
    std::cin >> _dirName;
}

void DirProc::process()
{
    std::filesystem::path path(_dirName);
    if(!std::filesystem::exists(path))
    {
        std::cout << path << " does not exist" << std::endl;
        return;
    }

    std::regex pattern("\\.exe$");
    for(const auto &entry : std::filesystem::directory_iterator(path))
    {
        auto fileName = entry.path().lexically_relative(path).string();
        if(std::regex_search(fileName, pattern))
        {
            _fileList.push_back(fileName);
        }
        ++_filesCount;
    }
    print();
}

void DirProc::print() const
{
    if(_filesCount == 0)
    {
        std::cout << _dirName << " directory has no files" << std::endl;
        return;
    }
    std::cout << _dirName << " directory total files count: " << _filesCount << std::endl;

    if(_fileList.empty())
    {
        std::cout << _dirName << " directory has no exe-files" << std::endl;
        return;
    }
    std::cout << _dirName << " directory has exe-files:" << std::endl;
    for(const auto &fileName : _fileList)
    {
        std::cout << fileName << std::endl;
    }
}
