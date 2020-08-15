#ifndef DRAGON_H
#define DRAGON_H

#include <memory>
#include "enemy.h"
#include "dragonhoard.h"

class Dragon: public Enemy {
    std::shared_ptr<DragonHoard> dragonHoard;
    public:
    Dragon(int x, int y, std::shared_ptr<DragonHoard> dragonHoard);
    virtual void beAttacked(std::shared_ptr<Player>& player) override;
    void setGoldPickable() override;
    bool checkPlayer(int row, int col) override;
};

#endif

