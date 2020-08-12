#ifndef CHARACTER_H
#define CHARACTER_H

#include "state.h"

class Character: public State {
    int health;
    int attack;
    int defense;
    int gold;
    bool Alive;
    public:
    Character(int x, int y, int health, int attack, int defense, int gold);
    void addHealth(int health);
    //void addGold(int gold);
    //void minusGold(int gold);
    int getGold();
    int getAttack();
    int getHealth();
    int getDefense();
    bool isAlive();
};

#endif
