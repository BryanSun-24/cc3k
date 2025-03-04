#ifndef DRAGONHOARD_H
#define DRAGONHOARD_H

#include "treasure.h"

class DragonHoard: public Treasure {
    public:
    DragonHoard(int x, int y, std::shared_ptr<Player> player);
    void addGold() override;
    void changePickable();
};

#endif

