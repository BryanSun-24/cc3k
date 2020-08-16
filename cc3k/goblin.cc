#include "goblin.h"
#include "human.h"
#include "dwarf.h"
#include "elf.h"
#include "orcs.h"
#include "merchant.h"
#include "halfling.h"
#include "dragon.h"


Goblin::Goblin(int x, int y, std::shared_ptr<Buff> buff):Player{x,y,110,15,20,0,"Goblin",110,buff} {}

void Goblin::beAttacked(std::shared_ptr<Enemy>& enemy) {
    enemy->attack(*this);
}


void Goblin::attack(Human& human) {
    int damage = std::ceil((((100)  * (this->getAttack() + this->attackBuff())) /  (100 + human.getDefense())));
    human.addHealth(-1 * damage);
    if(!human.isAlive()){
        this->addGold(5);
    }
}

void Goblin::attack(Dwarf& dwarf) {
    int damage = std::ceil((((100)  * (this->getAttack() + this->attackBuff())) /  (100 + dwarf.getDefense())));
    dwarf.addHealth(-1 * damage);
    if(!dwarf.isAlive()){
        this->addGold(5);
    }
}

void Goblin::attack(Elf&  elf) {
    int damage = std::ceil((((100)  * (this->getAttack() + this->attackBuff())) /  (100 + elf.getDefense())));
    elf.addHealth(-1 * damage);
    if(!elf.isAlive()){
        this->addGold(5);
    }
}

void Goblin::attack(Orcs& orcs) {
    int damage = std::ceil((((100)  * (this->getAttack() + this->attackBuff())) /  (100 + orcs.getDefense())));
    orcs.addHealth(-1 * damage);
    if(!orcs.isAlive()){
        this->addGold(5);
    }
}

void Goblin::attack(Merchant&  merchant){
    int damage = std::ceil((((100)  * (this->getAttack() + this->attackBuff())) /  (100 + merchant.getDefense())));
    merchant.addHealth(-1 * damage);
    if(!merchant.isAlive()){
        this->addGold(5);
    }   
}

void Goblin::attack(Halfling& halfling){
    int damage = std::ceil((((100)  * (this->getAttack() + this->attackBuff())) /  (100 + halfling.getDefense())));
    int randomAttack = rand() % 2;
    if(randomAttack == 0){
        halfling.addHealth(-1 * damage);
        if(!halfling.isAlive()){
        this->addGold(5);
        }
    }
}

void Goblin::attack(Dragon& dragon){
    int damage = std::ceil((((100)  * (this->getAttack() + this->attackBuff())) /  (100 + dragon.getDefense())));
    dragon.addHealth(-1 * damage);
    if(!dragon.isAlive()){
        this->addGold(5);
    }
}


