#ifndef DRAGONHOARD_H
#define DRAGONHOARD_H

#include "treasure.h"

class DragonHoard: public Treasure {
    int getGold() override;
    void addGold() override;
};

#endif

