#ifndef SHADE_H
#define SHADE_H
#include "player.h"

class Buff;

class Shade: public Player {
    public:
    Shade(int x, int y, std::shared_ptr<Buff> buff);
    virtual void specialAbility() override;
};

#endif

