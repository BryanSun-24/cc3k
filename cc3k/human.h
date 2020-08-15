#ifndef HUMAN_H
#define HUMAN_H
#include <vector>
#include <memory>

#include "enemy.h"
#include "normal.h"

class Human: public Enemy {
    public:
    Human(int x, int y);
    virtual void attack(Shade& shade) override;
    virtual void attack(Drow& drow) override;
    virtual void attack(Vampire& vampire) override;
    virtual void attack(Troll& troll) override;
    virtual void attack(Goblin& goblin) override;
    virtual void beAttacked(std::shared_ptr<Player>& player) override;
};

#endif

