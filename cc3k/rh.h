#ifndef RH_H
#define RH_H

#include "potion.h"

class RH: public Potion {
    int getEffect() override;
    void addBuff() override;
};

#endif
