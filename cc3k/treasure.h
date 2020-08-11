#ifndef TREASURE_H
#define TREASURE_H

#include "item.h"
#include <memory>

class Player;

class Treasure: public Item{
    protected:
    std::shared_ptr<Player> player;
    public:
    virtual int getGold();
    virtual void addGold();
};

#endif

