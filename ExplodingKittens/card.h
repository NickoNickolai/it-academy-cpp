#ifndef CARD_H
#define CARD_H

#include <ostream>

enum class CardType
{
    UNKNOWN,
    PASS,
    EXPLODE,    // 4
    DEFUSE,     // 6
    ATTACK,     // 4
    SHUFFLE,    // 4
    SKIP,       // 4
    NOPE,       // 5
    FUTURE,     // 5
    FAVOR,      // 4
    CAT         // 4x5(4)
};

class Card
{
public:
    Card();
    Card(CardType type);

    // Получение типа карты
    CardType type() const { return _type; }

    // Получение названия карты
    std::string name() const { return typeToName(_type); }

public:
    friend std::ostream &operator <<(std::ostream &out, const Card &card);

private:
    std::string typeToName(CardType type) const;

private:
    CardType _type;
};

#endif // CARD_H
