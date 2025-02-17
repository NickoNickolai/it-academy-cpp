#include "card.h"

Card::Card()
    : Card(CardType::UNKNOWN)
{}

Card::Card(CardType type)
    : _type(type)
{}

std::string Card::typeToName(CardType type) const
{
    switch(type)
    {
    case CardType::PASS:    return "pass";
    case CardType::EXPLODE: return "explode";
    case CardType::DEFUSE:  return "def";
    case CardType::ATTACK:  return "att";
    case CardType::SHUFFLE: return "shf";
    case CardType::SKIP:    return "skp";
    case CardType::FUTURE:  return "fut";
    case CardType::NOPE:    return "nop";
    case CardType::FAVOR:   return "fav";
    case CardType::CAT:     return "cat";
    default:                return "unk";
    }
}

std::ostream &operator <<(std::ostream &out, const Card &card)
{
    return out << card.name();
}
