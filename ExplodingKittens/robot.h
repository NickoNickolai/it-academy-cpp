#ifndef ROBOT_H
#define ROBOT_H

#include "player.h"

class Robot : public Player
{
public:
    Robot();
    Robot(std::string name);
    ~Robot();

public slots:
    void reqCard(PlayerState state) override;
    void reqNope(PlayerState state) override;
    Card favorCard() override;

private:
    static inline int _uid = 0;
};

#endif // ROBOT_H
