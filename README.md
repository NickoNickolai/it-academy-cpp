# Module 1

## helloworld

"HelloWorld" проект на C++ с использованием виджетов Qt.

*Основные функции:*

- отображение приветственной строки на форме и стандартной консоли вывода
- ввод имени пользователя для кастомизации приветственной строки
- очистка виджета приветственной строки

# Module 2

## factorial

Вычисление факториала 5 в типах int и float в зависимости от директивы препроцессора.

## sysinfo

Получение информации об ОС и компиляторе.

*Проверены ОС:*
- Microsoft Windows 10
- Linux Ubuntu 20.04
- Linux OpenSUSE 15.5
- FreeBSD 14.1
- Haiku R1

*Проверены компиляторы:*
- GNU GCC
- Clang
- MSVC
- Borland
- NVCC

# Module 3

## tablemult

Вывод в консоль таблицы умножения задаваемой размерности с помощью циклов for, while, do-while.

## itergame

Консольная итерационная игра.

*Правила*

На каждой итерации игроки (функции) поочередно выдают числа, чередуя положительные из диапазона `[1..5]` и отрицательные из диапазона `[-5..-1]`, которые добавляются к общему счёту игры.

*Условия победы:*
- Выигрывает игрок, после хода которого счёт превысил максимальный счёт игры (например `50`).
- Если за определённый лимит итераций (например `100`) нет победителя, то объявляется ничья и игра завершается.

# Module 4

## numshifter

Вывод целого числа, к которому применён сдвиг на 2 позиции:
- влево если число чётное и положительное
- вправо в противном случае

# Module 5

## shapes

Обработчик фигур типа `Shape`. Сопоставление типа фигуры с названием и наоборот.

# Module 6

## cstrproc

Переворачивание С-style строки.

## dynmatrix

Динамическое выделение/удаление 2D матрицы, заполнение значениями по правилу `i*j`.

## randvector

Сортировка по возрастанию вектора случайных значений.

## smartarray

Работа с массивом через smart-pointer - поиск min и max значений.

# Module 7

## uniquearray

Работа с массивом через `unique_ptr`:
- заполнение
- вывод в консоль

## sharedarray

Работа с массивом через `shared_ptr`/`weak_ptr`:
- заполнение
- вывод в консоль
- вычисление суммы всех элементов
- поиск min и max значений

## funoverload

Перегрузка ф-ции `print()` для типов:
- `int`
- `float`
- `std::string`
- `char*` *(массив)*
- `int*` *(массив)*
- `std::vector<int>`
- `std::shared_ptr<int>`
- `std::unique_ptr<double>`

# Module 8

## book

Класс, описывающий книгу.

# Module 9

## forest

Модель леса и деревьев. Основные особенности:
- Тип дерева задается перечислением
- Лес может выращивать деревья, получать их во владение и вырубать
- Хранение списка деревьев реализовано в хэш-таблице для оптимального поиска по id дерева для вырубки
- Леса могут объединяться в один, деревья при этом перемещаются в объединённый

# Module 10

## forest

Расширенная модель леса и деревьев. Основные особенности:
- Типы лесов и деревьев образуют иерархии
- Леса каждого типа проверяют возможность добавления дерева данного типа
- Для сохранения логики перемещения `unique_ptr` дерева в лес использованы сигнатуры с `l-value` и `r-value` ссылками

# Module 13

## carservice

Модель СТО, основанная на шаблонах. Основные особенности:
- Типы СТО задаются типами шаблона
- Типы машин образуют иерархию
- Машины можно добавлять в СТО соответствующего типа
- Очередь СТО лимитирована
- Гараж с готовыми машинами инкапсулирован в СТО

# Module 15

## currency

Конвертер валют на основе фреймфорка Qt. Основные особенности:
- Суммы для конвертации задаются в виджетах ввода-вывода
- При вводе входная сумма конвертируется в выходную и наоборот
- В виджетах ввода-вывода предусмотрен валидатор ввода
- Типы валют задаются в выпадающих списках рядом с виджетами ввода-вывода
- Курсы валют задаются в настройках (кнопка `Настройки`)
- Настройки курсов валют сохраняются в ini-файле
