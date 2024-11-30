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

    // Получение типа фигуры по её имени
    static Shape get_shape(const std::string &name);
};
}

#endif // HANDLER_H
