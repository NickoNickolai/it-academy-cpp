#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book
{
public:
    Book(const std::string &title, const std::string &author, int year, const std::string &isbn);
    Book(const Book &book);
    ~Book();

    // Геттеры для доступа к полям класса
    std::string title() const { return _title; }
    std::string author() const { return _author; }
    int year() const { return _year; }
    std::string isbn() const { return std::string(_isbn); }

    // Вывод информации об объекте в консоль
    void printInfo() const;

private:
    std::string _title;
    std::string _author;
    int _year;
    char *_isbn;
};

#endif // BOOK_H
