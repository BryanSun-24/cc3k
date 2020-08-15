#ifndef MERCHANT_H
#define MERCHANT_H

#include <memory>
#include "enemy.h"
#include "merchanhoard.h"

class Merchant: public Enemy {
    bool isAttack;
    public:
    Merchant(int x, int y);
    virtual void attack(Shade& shade) override;
    virtual void attack(Drow& drow) override;
    virtual void attack(Vampire& vampire) override;
    virtual void attack(Troll& troll) override;
    virtual void attack(Goblin& goblin) override;
    virtual void beAttacked(std::shared_ptr<Player>& player) override;
};

#endif

