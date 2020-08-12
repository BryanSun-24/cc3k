#ifndef CHARACTER_H
#define CHARACTER_H

#include "state.h"

class Character: public State {
    int health;
    int attack;
    int defense;
    int gold;
    bool isAlive;
    public:
    Character(int x, int y, int health, int attack, int defense, int gold);
};

#endif
