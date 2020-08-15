#include "goblin.h"
#include "human.h"
#include "dwarf.h"
#include "elf.h"
#include "orcs.h"
#include "merchant.h"
#include "halfling.h"
#include "dragon.h"


Goblin::Goblin(int x, int y, std::shared_ptr<Buff> buff):Player{x,y,110,15,20,0,110,buff} {}

void Goblin::beAttacked(std::shared_ptr<Enemy>& enemy) {
    enemy->attack(*this);
}


void Goblin::attack(Human& human) {
    //std::cout << "called attack human" << std::endl;
    int damage = std::ceil((((100)  * (this->getAttack() + this->attackBuff())) /  (100 + human.getDefense())));
    human.addHealth(-1 * damage);
    if(!human.isAlive()){
        this->addGold(5);
    }
}

void Goblin::attack(Dwarf& dwarf) {
    //std::cout << "called attack Dwarf" << std::endl;
    int damage = std::ceil((((100)  * (this->getAttack() + this->attackBuff())) /  (100 + dwarf.getDefense())));
    dwarf.addHealth(-1 * damage);
    if(!dwarf.isAlive()){
        this->addGold(5);
    }
}

void Goblin::attack(Elf&  elf) {
    //std::cout << "called attack Elf" << std::endl;
    int damage = std::ceil((((100)  * (this->getAttack() + this->attackBuff())) /  (100 + elf.getDefense())));
    elf.addHealth(-1 * damage);
    if(!elf.isAlive()){
        this->addGold(5);
    }
}

void Goblin::attack(Orcs& orcs) {
    //std::cout << "called attack Orcs" << std::endl;
    int damage = std::ceil((((100)  * (this->getAttack() + this->attackBuff())) /  (100 + orcs.getDefense())));
    orcs.addHealth(-1 * damage);
    if(!orcs.isAlive()){
        this->addGold(5);
    }
}

void Goblin::attack(Merchant&  merchant){
    //std::cout << "called attack Merchant" << std::endl;
    int damage = std::ceil((((100)  * (this->getAttack() + this->attackBuff())) /  (100 + merchant.getDefense())));
    merchant.addHealth(-1 * damage);
    if(!merchant.isAlive()){
        this->addGold(5);
    }   
}

void Goblin::attack(Halfling& halfling){
    //std::cout << "called attack Halfling" << std::endl;
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
    //std::cout << "called attack dragon" << std::endl;
    int damage = std::ceil((((100)  * (this->getAttack() + this->attackBuff())) /  (100 + dragon.getDefense())));
    dragon.addHealth(-1 * damage);
    if(!dragon.isAlive()){
        this->addGold(5);
    }
}


