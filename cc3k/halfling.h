#ifndef HALFLING_H
#define HALFLING_H
#include "enemy.h"

class Halfling: public Enemy {
    public:
    Halfling(int x, int y, int gold);
    virtual void beAttacked(std::shared_ptr<Player>& player) override;
};

#endif

