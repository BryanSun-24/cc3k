#ifndef ENEMY_H
#define ENEMY_H

#include "character.h"
#include <memory>

class Player;

class Enemy: public Character {
    public:
    Enemy(int x, int y, int health, int attack, int defense, int gold);
    void attack(std::shared_ptr<Player> player);
    void specialAbility();
};

#endif
