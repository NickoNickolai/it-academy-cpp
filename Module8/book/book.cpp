#include "book.h"
#include <cstring>
#include <iostream>

Book::Book(const std::string &title, const std::string &author, int year, const std::string &isbn)
    : _title(title), _author(author), _year(year)
{
    _isbn = new char[isbn.size() + 1] { 0 };
    memcpy(_isbn, isbn.data(), isbn.size());
}

Book::Book(const Book &book)
    : Book(book.title(), book.author(), book.year(), book.isbn())
{}

Book::~Book()
{
    delete[] _isbn;
}

void Book::printInfo() const
{
    std::cout << "ISBN " << _isbn << ": " << _author << " - "
              << _title << " (" << _year << ")" << std::endl;
}
