#include "character.h"

using namespace std;

Character::Character(int x, int y, int health, int attack, int defense, int gold):State{x,y},health{health},attack{attack},defense{defense},gold{gold},Alive{true}{}

void Character::addHealth(int health){
    this->health += health;
}

void Character::addGold(int gold){
    this->gold += gold;
}

int Character::getGold(){
    return this->gold;
}
int Character::getAttack() {
    return this->attack;
}
int Character::getHealth(){
    return this->health;
}
int Character::getDefense(){
    return this->defense;
}
bool Character::isAlive(){
    return this->Alive;
}

