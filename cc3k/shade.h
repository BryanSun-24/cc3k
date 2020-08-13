#ifndef SHADE_H
#define SHADE_H
#include "player.h"

class Shade: public Player {
    public:
    Shade(int x, int y);
    virtual void specialAbility() override;
};

#endif

