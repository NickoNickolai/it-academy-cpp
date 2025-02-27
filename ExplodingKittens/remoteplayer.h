#ifndef REMOTEPLAYER_H
#define REMOTEPLAYER_H

#include "player.h"

class RemotePlayer : public Player
{
public:
    RemotePlayer(std::string name);

    // Добавление карты в руку
    void addCard(Card card) override;

public slots:
    void reqCard(PlayerState state) override;
    void reqNope(PlayerState state) override;
    void reqFavor() override;
    void addFuture(const Card &card) override;
    void popFuture() override;
    void resetFuture() override;
};

#endif // REMOTEPLAYER_H
