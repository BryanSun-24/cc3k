#ifndef DRAGON_H
#define DRAGON_H

#include <memory>
#include "enemy.h"
#include "dragonhoard.h"

class Dragon: public Enemy {
    std::shared_ptr<DragonHoard> dragonHoard;
    public:
    Dragon(int x, int y, std::shared_ptr<DragonHoard> dragonHoard);
    virtual void attack(Shade& shade) override;
    virtual void attack(Drow& drow) override;
    virtual void attack(Vampire& vampire) override;
    virtual void attack(Troll& troll) override;
    virtual void attack(Goblin& goblin) override;
    virtual void beAttacked(std::shared_ptr<Player>& player) override;
    void setGoldPickable() override;
    bool checkPlayer(int row, int col) override;
};

#endif

