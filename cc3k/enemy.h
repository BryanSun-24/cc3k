#ifndef ENEMY_H
#define ENEMY_H

#include "character.h"
#include <memory>

class Player;

class Enemy: public Character {
    public:
    void getGold();
    void attack(std::shared_ptr<Player> player);
    void specialAbility();
};

#endif
