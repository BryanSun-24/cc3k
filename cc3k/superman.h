#ifndef SUPERMAN_H
#define SUPERMAN_H

#include "enemy.h"

class Superman: public Enemy {
    public:
    Superman(int x, int y);
    virtual void attack(Shade& shade) override;
    virtual void attack(Drow& drow) override;
    virtual void attack(Vampire& vampire) override;
    virtual void attack(Troll& troll) override;
    virtual void attack(Goblin& goblin) override;
    virtual void beAttacked(std::shared_ptr<Player>& player) override;
};

#endif

