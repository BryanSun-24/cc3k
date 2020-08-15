#ifndef ELF_H
#define ELF_H

#include "enemy.h"

class Elf: public Enemy {
    public:
    Elf(int x, int y, int gold);
    void attack(Shade& shade) override;
    void attack(Vampire& vampire) override;
    void attack(Troll& troll) override;
    void attack(Goblin& goblin) override;
    virtual void beAttacked(std::shared_ptr<Player>& player) override;
};

#endif

