#include "buff.h"

Buff::Buff():attack{0},defense{0},health{0} {}

int Buff::getAttack(){
    return this->attack;
}

int Buff::getDefense(){
    return this->defense;
}

int Buff::getHealth(){
    int health = this->health;
    this->health = 0;
    return health;
}
    
void Buff::attackPotion(int attack){
    this->attack += attack;
}

void Buff::defensePotion(int defense){
    this->defense += defense;
}

void Buff::healthPotion(int health){
    this->health += health;
}

void Buff::reset(){
    this->attack = 0;
    this->defense = 0;
    this->health = 0;
}

