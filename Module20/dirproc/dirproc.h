#ifndef DIRPROC_H
#define DIRPROC_H

#include <string>
#include <vector>

class DirProc
{
public:
    DirProc();

    // Ввод имени папки
    void input();

    // Выполнение обработки папки
    void process();

private:
    // Вывод в консоль результатов
    void print() const;

private:
    std::string _dirName;
    std::vector<std::string> _fileList;
    int _filesCount;
};

#endif // DIRPROC_H
