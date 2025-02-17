#ifndef CAR_H
#define CAR_H

#include <ostream>
#include <string>

class Car
{
public:
    Car(const std::string &name);
    Car(const std::string &name, bool isRepaired);
    virtual ~Car() = default;

    // Починка машины
    void repair() { _isRepaired = true; }

    // Получение состояния машины (отремонтирована или нет)
    bool isRepaired() const { return _isRepaired; }

    // Получение имени машины
    std::string name() const { return _name; }

public:
    friend std::ostream &operator <<(std::ostream &out, const Car &car);

private:
    std::string _name;
    bool _isRepaired;
};

#endif // CAR_H
