#ifndef TREASURE_H
#define TREASURE_H

#include "item.h"
#include <memory>
#include "player.h"

#include <iostream>

class Treasure: public Item{
    protected:
    bool pickable;
    std::shared_ptr<Player> player;
    public:
    Treasure(int x, int y, std::string type, int num, bool pickable, std::shared_ptr<Player> player);
    virtual ~Treasure() {};
    int getGold();
    virtual void addGold() = 0;
    bool isPickable();
};

#endif

