#ifndef NORMAL_H
#define NORMAL_H

#include "treasure.h"

class Normal: public Treasure {
    public:
    Normal(int x, int y, std::shared_ptr<Player> player);
    void addGold() override;
};

#endif
