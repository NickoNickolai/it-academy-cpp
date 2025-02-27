#ifndef HUMAN_H
#define HUMAN_H

#include "player.h"

class Human : public Player
{
public:
    Human(std::string name);

public slots:
    void reqCard(PlayerState state) override;
    void reqNope(PlayerState state) override;
    void reqFavor() override;
};

#endif // HUMAN_H
