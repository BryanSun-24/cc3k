#ifndef ENEMY_H
#define ENEMY_H

#include "character.h"
#include <memory>
#include <iostream>

class Player;

class Shade;
class Drow;
class Vampire;
class Troll;
class Goblin;

class Enemy: public Character {
    bool moveAble;
    public:
    Enemy(int x, int y, int health, int attack, int defense, int gold, bool moveAble);
    void specialAbility();
    virtual bool checkPlayer(int row, int col);
    bool isMovable();
    virtual void attack(Shade& shade) = 0;
    virtual void attack(Drow& drow) = 0;
    virtual void attack(Vampire& vampire) = 0;
    virtual void attack(Troll& troll) = 0;
    virtual void attack(Goblin& goblin) = 0;
    virtual void beAttacked(std::shared_ptr<Player>& player) = 0;
    virtual void setGoldPickable() {};
};

#endif
