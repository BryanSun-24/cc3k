#ifndef MERCHANHOARD_H
#define MERCHANHOARD_H

#include "treasure.h"

class MerchanHoard: public Treasure {
    public:
    MerchanHoard(int x, int y, std::shared_ptr<Player> player);
    void addGold() override;
};

#endif
