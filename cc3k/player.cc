#include "player.h"
#include "enemy.h"
#include "buff.h"

#include "human.h"
#include "dwarf.h"
#include "elf.h"
#include "orcs.h"
#include "merchant.h"
#include "halfling.h"
#include "dragon.h"
#include "superman.h"


using namespace std;

Player::Player(int x, int y, int health, int attack, int defense, int gold, std::string race, int maxHp, std::shared_ptr<Buff> buff):Character{x,y,health,attack,defense,gold,race},maxHp{maxHp},buff{buff} {}

// directly add or minus health from buff
void Player::gainHp(){
    this->addHealth(this->buff->getHealth());
    if(this->getHealth() > this->maxHp){
        this->setMaxHealth(this->maxHp);
    }
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

std::shared_ptr<Buff> Player::getBuff(){
    return this->buff;
}

int Player::getMax(){
    return this->maxHp;
}

void Player::attack(Human& human) {
    //std::cout << "called attack human" << std::endl;
    int damage = std::ceil((((100)  * (this->getAttack() + this->attackBuff())) /  (100 + human.getDefense())));
    human.addHealth(-1 * damage);
}

void Player::attack(Dwarf& dwarf) {
    //std::cout << "called attack Dwarf" << std::endl;
    int damage = std::ceil((((100)  * (this->getAttack() + this->attackBuff())) /  (100 + dwarf.getDefense())));
    dwarf.addHealth(-1 * damage);
}

void Player::attack(Elf&  elf) {
    //std::cout << "called attack Elf" << std::endl;
    int damage = std::ceil((((100)  * (this->getAttack() + this->attackBuff())) /  (100 + elf.getDefense())));
    elf.addHealth(-1 * damage);
}

void Player::attack(Orcs& orcs) {
    //std::cout << "called attack Orcs" << std::endl;
    int damage = std::ceil((((100)  * (this->getAttack() + this->attackBuff())) /  (100 + orcs.getDefense())));
    orcs.addHealth(-1 * damage);
    
}

void Player::attack(Merchant&  merchant){
    //std::cout << "called attack Merchant" << std::endl;
    int damage = std::ceil((((100)  * (this->getAttack() + this->attackBuff())) /  (100 + merchant.getDefense())));
    merchant.addHealth(-1 * damage);
}

void Player::attack(Halfling& halfling){
    //std::cout << "called attack Halfling" << std::endl;
    int damage = std::ceil((((100)  * (this->getAttack() + this->attackBuff())) /  (100 + halfling.getDefense())));
    int randomAttack = rand() % 2;
    if(randomAttack == 0){
        halfling.addHealth(-1 * damage);
    }
}

void Player::attack(Dragon& dragon){
    //std::cout << "called attack dragon" << std::endl;
    int damage = std::ceil((((100)  * (this->getAttack() + this->attackBuff())) /  (100 + dragon.getDefense())));
    dragon.addHealth(-1 * damage);
}

void Player::attack(Superman& superman){
    //std::cout << "called attack dragon" << std::endl;
    int damage = std::ceil((((100)  * (this->getAttack() + this->attackBuff())) /  (100 + superman.getDefense())));
    superman.addHealth(-1 * damage);
}



