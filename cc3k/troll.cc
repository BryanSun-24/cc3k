#include "troll.h"
#include "human.h"
#include "dwarf.h"
#include "elf.h"
#include "orcs.h"
#include "merchant.h"
#include "halfling.h"
#include "dragon.h"


Troll::Troll(int x, int y, std::shared_ptr<Buff> buff):Player{x,y,120,25,15,0,"Troll",120,buff} {}

void Troll::beAttacked(std::shared_ptr<Enemy>& enemy) {
    enemy->attack(*this);
}

void Troll::attack(Human& human) {
    int damage = std::ceil((((100)  * (this->getAttack() + this->attackBuff())) /  (100 + human.getDefense())));
    human.addHealth(-1 * damage);
    this->addHealth(5);
    if(this->getHealth() > this->getMax()){
        this->setMaxHealth(this->getMax());
    }
}

void Troll::attack(Dwarf& dwarf) {
    int damage = std::ceil((((100)  * (this->getAttack() + this->attackBuff())) /  (100 + dwarf.getDefense())));
    dwarf.addHealth(-1 * damage);
    this->addHealth(5);
    if(this->getHealth() > this->getMax()){
        this->setMaxHealth(this->getMax());
    }
}

void Troll::attack(Elf&  elf) {
    int damage = std::ceil((((100)  * (this->getAttack() + this->attackBuff())) /  (100 + elf.getDefense())));
    elf.addHealth(-1 * damage);
    this->addHealth(5);
    if(this->getHealth() > this->getMax()){
        this->setMaxHealth(this->getMax());
    }
}

void Troll::attack(Orcs& orcs) {
    int damage = std::ceil((((100)  * (this->getAttack() + this->attackBuff())) /  (100 + orcs.getDefense())));
    orcs.addHealth(-1 * damage);
    this->addHealth(5);
    if(this->getHealth() > this->getMax()){
        this->setMaxHealth(this->getMax());
    }
}

void Troll::attack(Merchant&  merchant){
    int damage = std::ceil((((100)  * (this->getAttack() + this->attackBuff())) /  (100 + merchant.getDefense())));
    merchant.addHealth(-1 * damage);
    this->addHealth(5);    
    if(this->getHealth() > this->getMax()){
        this->setMaxHealth(this->getMax());
    }
}

void Troll::attack(Halfling& halfling){
    int damage = std::ceil((((100)  * (this->getAttack() + this->attackBuff())) /  (100 + halfling.getDefense())));
    int randomAttack = rand() % 2;
    if(randomAttack == 0){
        halfling.addHealth(-1 * damage);
        this->addHealth(5);
        if(this->getHealth() > this->getMax()){
            this->setMaxHealth(this->getMax());
        }
    }
}

void Troll::attack(Dragon& dragon){
    int damage = std::ceil((((100)  * (this->getAttack() + this->attackBuff())) /  (100 + dragon.getDefense())));
    dragon.addHealth(-1 * damage);
    this->addHealth(5);
    if(this->getHealth() > this->getMax()){
        this->setMaxHealth(this->getMax());
    }
}

void Troll::everyTurn(){
    this->addHealth(5);
    if(this->getHealth() > this->getMax()){
        this->setMaxHealth(this->getMax());
    }
}

