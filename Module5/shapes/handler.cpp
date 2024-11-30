#include "handler.h"
#include <iostream>

namespace Shapes
{

void Handler::print_shape(Shape shape)
{
    std::cout << get_name(shape) << std::endl;
}

std::string Handler::get_name(Shape shape)
{
    switch(shape)
    {
    case Shape::CIRCLE:
        return "circle";
    case Shape::SQUARE:
        return "square";
    case Shape::TRIANGLE:
        return "triangle";
    default:
        return "unknown";
    }
}

}
