#ifndef SHADE_H
#define SHADE_H
#include "player.h"


class Shade: public Player {
    public:
    Shade(int x, int y, std::shared_ptr<Buff> buff);
    void beAttacked(std::shared_ptr<Enemy>& enemy) override;
};

#endif

