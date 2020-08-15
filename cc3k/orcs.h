#ifndef ORCS_H
#define ORCS_H

#include "enemy.h"

class Orcs: public Enemy {
    public:
    Orcs(int x, int y, int gold);
    virtual void attack(Goblin& goblin) override;
    virtual void beAttacked(std::shared_ptr<Player>& player) override;
};

#endif

