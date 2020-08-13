#ifndef SMALL_H
#define SMALL_H

#include "treasure.h"

class Small: public Treasure {
    public:
    Small(int x, int y, int num, std::shared_ptr<Player> player);
    void addGold() override;
};

#endif
