#include <iostream>
#include "handler.h"

int main()
{
    auto shape = Shapes::Shape::TRIANGLE;
    Shapes::Handler::print_shape(shape);

    std::cout << "Enter shape name: ";
    std::string name;
    std::cin >> name;

    shape = Shapes::Handler::get_shape(name);
    Shapes::Handler::print_shape(shape);

    return 0;
}
