#ifndef WD_H
#define WD_H

#include "potion.h"

class WD: public Potion {
    int getEffect() override;
    void addBuff() override;
};

#endif
