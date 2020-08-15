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
    int maxHp;   
    std::shared_ptr<Buff> buff; 
    public:
    Player(int x, int y, int health, int attack, int defense, int gold, int maxHp, std::shared_ptr<Buff> buff);
    virtual ~Player() {};
    virtual void gainHp();
    virtual int attackBuff();
    virtual int defenseBuff(); 
    void resetBuff();
    //void attack(std::shared_ptr<Enemy> enemy);
    virtual void attack(Human& human);
    virtual void attack(Dwarf& dwarf);
    virtual void attack(Elf& elf);
    virtual void attack(Orcs& orcs);
    virtual void attack(Merchant& merchant);
    virtual void attack(Halfling& halfling);
    virtual void attack(Dragon& dragon);
    virtual void beAttacked(std::shared_ptr<Enemy>& enemy) = 0;
    std::shared_ptr<Buff> getBuff();
};

#endif
