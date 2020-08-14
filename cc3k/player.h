#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"
#include <memory>
#include "buff.h"

class Enemy;

class Player: public Character {
    std::shared_ptr<Buff> buff;
    int maxHp;    
    public:
    Player(int x, int y, int health, int attack, int defense, int gold, int maxHp, std::shared_ptr<Buff> buff);
    void gainHp(int hp);
    int attackBuff();
    int defenseBuff(); 
    void resetBuff();
    void attack(std::shared_ptr<Enemy> enemy);
    virtual void specialAbility() = 0;
    std::shared_ptr<Buff> getBuff();
};

#endif
