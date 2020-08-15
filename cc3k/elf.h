#ifndef ELF_H
#define ELF_H

#include "enemy.h"

class Elf: public Enemy {
    public:
    Elf(int x, int y, int gold);
    virtual void attack(Shade& shade) override;
    virtual void attack(Drow& drow) override;
    virtual void attack(Vampire& vampire) override;
    virtual void attack(Troll& troll) override;
    virtual void attack(Goblin& goblin) override;
    virtual void beAttacked(std::shared_ptr<Player>& player) override;
};

#endif

