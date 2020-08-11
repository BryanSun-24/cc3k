#ifndef MERCHANHOARD_H
#define MERCHANHOARD_H

#include "treasure.h"

class MerchanHoard: public Treasure {
    int getGold() override;
    void addGold() override;
};

#endif
