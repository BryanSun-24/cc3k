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
    bool fmoveAble;
    bool hostile;
    public:
    Enemy(int x, int y, int health, int attack, int defense, int gold, std::string race, bool moveAble, bool fmoveAble, bool hostile);
    virtual ~Enemy() {};
    virtual bool checkPlayer(int row, int col);
    bool isMovable();
    bool isfMovable();
    bool isHostile();
    virtual void attack(Shade& shade);
    virtual void attack(Drow& drow);
    virtual void attack(Vampire& vampire);
    virtual void attack(Troll& troll);
    virtual void attack(Goblin& goblin);
    virtual void beAttacked(std::shared_ptr<Player>& player) = 0;
    virtual void setGoldPickable() {};
    virtual void setHostile();
    void setPause();
};

#endif
