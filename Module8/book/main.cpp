#include <iostream>
#include "book.h"

int main()
{
    Book book("Effective Modern C++", "S.Meyers", 2016, "978-5-8459-2000-3");
    std::cout << "Author: " << book.author() << std::endl;
    std::cout << "Title: " << book.title() << std::endl;
    std::cout << "Year: " << book.year() << std::endl;
    std::cout << "ISBN: " << book.isbn() << std::endl;
    std::cout << "Orig book info: ";
    book.printInfo();

    auto book_copy = new Book(book);
    std::cout << "Book copy info: ";
    book_copy->printInfo();
    delete book_copy;

    return 0;
}
