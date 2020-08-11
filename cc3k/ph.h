#ifndef PH_H
#define PH_H

#include "potion.h"

class PH: public Potion {
    int getEffect() override;
    void addBuff() override;
};

#endif
