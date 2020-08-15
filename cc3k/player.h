#ifndef PLAYER_H
#define PLAYER_H

#include <memory>
#include <cmath>
#include "character.h"
#include "buff.h"

class Human;
class Dwarf;
class Orcs;
class Elf;
class Merchant;
class Halfling;
class Dragon;

class Enemy;

class Player: public Character {
    protected:
    std::shared_ptr<Buff> buff;
    int maxHp;    
    public:
    Player(int x, int y, int health, int attack, int defense, int gold, int maxHp, std::shared_ptr<Buff> buff);
    void gainHp(int hp);
    int attackBuff();
    int defenseBuff(); 
    void resetBuff();
    //void attack(std::shared_ptr<Enemy> enemy);
    virtual void attack(Human& human) = 0;
    virtual void attack(Dwarf& dwarf) = 0;
    virtual void attack(Elf& elf) = 0;
    virtual void attack(Orcs& orcs) = 0;
    virtual void attack(Merchant& merchant) = 0;
    virtual void attack(Halfling& halfling) = 0;
    virtual void attack(Dragon& dragon) = 0;
    virtual void beAttacked(std::shared_ptr<Enemy>& enemy) = 0;
    virtual void specialAbility() = 0;
    std::shared_ptr<Buff> getBuff();
};

#endif
