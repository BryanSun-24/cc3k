#ifndef MERCHANT_H
#define MERCHANT_H

#include <memory>
#include "enemy.h"
#include "merchanhoard.h"

class Merchant: public Enemy {
    public:
    Merchant(int x, int y);
    virtual void beAttacked(std::shared_ptr<Player>& player) override;
};

#endif

