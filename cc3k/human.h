#ifndef HUMAN_H
#define HUMAN_H
#include <vector>
#include <memory>

#include "enemy.h"
#include "normal.h"

class Human: public Enemy {
    public:
    Human(int x, int y);
    virtual void beAttacked(std::shared_ptr<Player>& player) override;
};

#endif

