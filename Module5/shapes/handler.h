#ifndef HANDLER_H
#define HANDLER_H

#include <string>

namespace Shapes
{
enum class Shape
{
    UNKNOWN = -1,
    CIRCLE,
    SQUARE,
    TRIANGLE
};

class Handler
{
public:
    // Вывод названия фигуры в консоль
    static void print_shape(Shape shape);

    // Получение названия фигуры по её типу
    static std::string get_name(Shape shape);
};
}

#endif // HANDLER_H
