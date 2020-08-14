#ifndef TREASURE_H
#define TREASURE_H

#include "item.h"
#include <memory>
#include "player.h"

#include <iostream>

class Treasure: public Item{
    protected:
    std::shared_ptr<Player> player;
    public:
    Treasure(int x, int y, int num, std::shared_ptr<Player> player);
    int getGold();
    virtual void addGold() = 0;
};

#endif

