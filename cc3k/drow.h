#ifndef DROW_H
#define DROW_H
#include "player.h"

class Drow: public Player {
    public:
    Drow(int x, int y, std::shared_ptr<Buff> buff);
    void beAttacked(std::shared_ptr<Enemy>& enemy) override;
    void gainHp() override;
    int attackBuff() override;
    int defenseBuff() override; 
};

#endif

