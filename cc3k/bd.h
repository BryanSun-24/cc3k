#ifndef BD_H
#define BD_H

#include "potion.h"

class BD: public Potion {
    int getEffect() override;
    void addBuff() override;
};

#endif
