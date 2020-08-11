#ifndef SMALL_H
#define SMALL_H

#include "treasure.h"

class Small: public Treasure {
    int getGold() override;
    void addGold() override;
};

#endif
