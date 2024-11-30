#include "handler.h"

int main()
{
    auto shape = Shapes::Shape::TRIANGLE;
    Shapes::Handler::print_shape(shape);

    return 0;
}
