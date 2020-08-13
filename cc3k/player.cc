#include "player.h"
#include "enemy.h"
#include "buff.h"

using namespace std;

Player::Player(int x, int y, int health, int attack, int defense, int gold, int maxHp):Character{x,y,health,attack,defense,gold},maxHp{maxHp} {}

// directly add or minus health from buff
void Player::gainHp(int hp){
    this->addHealth(hp);
}
// calculate attack buff, will be calculated together with originial attack in the combat
int Player::attackBuff(){
    return this->buff->getAttack();
} 
// calculate defense buff, will be calculated together with originial defense in the combat
int Player::defenseBuff(){
    return this->buff->getDefense();
}

// reset buff to 0 whenever the player moves to next floor
void Player::resetBuff(){
    this->buff->reset();
}

void Player::attack(std::shared_ptr<Enemy> enemy){

}