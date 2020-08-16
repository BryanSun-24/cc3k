#ifndef BATMAN_H
#define BATMAN_H
#include "player.h"

class Batman: public Player {
    public:
    Batman(int x, int y, std::shared_ptr<Buff> buff);
    void beAttacked(std::shared_ptr<Enemy>& enemy) override;
};

#endif

