#ifndef NETSTRUCTS_H
#define NETSTRUCTS_H

#include <QByteArray>
#include <cstring>
#include "card.h"

enum class PacketType
{
    UNKNOWN,
    PLAYER_NAME,
    REQUEST_CARD,   // Запрос карты от клиента
    PLAY_CARD,      // Карта от клиента
    REQUEST_NOPE,   // Запрос отмены от клиента
    NOPE_CARD,      // Отмена от клиента
    REQUEST_FAVOR,  // Запрос карты на передачу оппоненту от клиента
    FAVOR_CARD,     // Карта на передачу оппоненту от клиента
    ADD_FUTURE,     // Добавление карты в кэш клиенту
    POP_FUTURE,     // Удаление карты из кэша клиента
    RESET_FUTURE,   // Сброс кэша клиента
    DECK_CARD,      // Карта, которой походила колода
    GAME_MESSAGE    // Игровое сообщение
};

#pragma pack(1)
struct NetworkPacket
{
    // Тип сообщения
    PacketType type;

    // Далее наличие полей в зависимости от типа сообщения

    // Тип карты
    Card card;

    // Значение отмены
    bool nope;

    // Состояние взорванности
    bool exploded;

    // Строка для имени игрока
    char name[16];

    // Строка игрового сообщения
    char message[64];

    NetworkPacket()
    {
        memset(this, 0, sizeof(*this));
    }
};
#pragma pack(0)

template <typename T>
QByteArray toQByteArray(const T &msg)
{
    return QByteArray(reinterpret_cast<const char *>(&msg), sizeof(msg));
}

#endif // NETSTRUCTS_H
