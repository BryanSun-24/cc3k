#ifndef MERCHANT_H
#define MERCHANT_H

#include <memory>
#include "enemy.h"
#include "merchanhoard.h"

class Merchant: public Enemy {
    bool isAttack;
    std::shared_ptr<MerchanHoard> hoard;
};

#endif

