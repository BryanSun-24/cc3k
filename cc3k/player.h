#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"
#include <memory>

class Buff;
class Enemy;

class Player: public Character {
    std::shared_ptr<Buff> buff;
    int maxHp;    
    public:
    void gainHp(int hp);
    void healthBuff(); 
    void resetBuff();
    void attack(std::shared_ptr<Enemy> enemy);
    void specialAbility();
};

#endif
