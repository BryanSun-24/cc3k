#ifndef BA_H
#define BA_H

#include "potion.h"

class BA: public Potion {
    int getEffect() override;
    void addBuff() override;
};

#endif