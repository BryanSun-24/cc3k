#ifndef WA_H
#define WA_H

#include "potion.h"

class WA: public Potion {
    int getEffect() override;
    void addBuff() override;
};

#endif
