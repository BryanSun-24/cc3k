#include "character.h"

Character::Character(int x, int y, int health, int attack, int defense, int gold, std::string race):State{x,y},health{health},attack{attack},defense{defense},gold{gold},Alive{true},race{race} {}

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
    if(this->health <= 0){
        this->Alive = false;
    } else {
        this->Alive = true;
    }
    return this->Alive;
}

std::string Character::getRaceType(){
    return this->race;
}

void Character::setMaxHealth(int health){
    this->health = health;
}

