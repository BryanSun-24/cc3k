#include "vampire.h"
#include "human.h"
#include "dwarf.h"
#include "elf.h"
#include "orcs.h"
#include "merchant.h"
#include "halfling.h"
#include "dragon.h"


Vampire::Vampire(int x, int y, std::shared_ptr<Buff> buff):Player{x,y,50,25,25,0,"Vampire",999999999,buff} {}

void Vampire::beAttacked(std::shared_ptr<Enemy>& enemy) {
    enemy->attack(*this);
}

void Vampire::attack(Human& human) {
    //std::cout << "called attack human" << std::endl;
    int damage = std::ceil((((100)  * (this->getAttack() + this->attackBuff())) /  (100 + human.getDefense())));
    human.addHealth(-1 * damage);
    this->addHealth(5);
}

void Vampire::attack(Dwarf& dwarf) {
    //std::cout << "called attack Dwarf" << std::endl;
    int damage = std::ceil((((100)  * (this->getAttack() + this->attackBuff())) /  (100 + dwarf.getDefense())));
    dwarf.addHealth(-1 * damage);
    this->addHealth(5);
}

void Vampire::attack(Elf&  elf) {
    //std::cout << "called attack Elf" << std::endl;
    int damage = std::ceil((((100)  * (this->getAttack() + this->attackBuff())) /  (100 + elf.getDefense())));
    elf.addHealth(-1 * damage);
    this->addHealth(5);
}

void Vampire::attack(Orcs& orcs) {
    //std::cout << "called attack Orcs" << std::endl;
    int damage = std::ceil((((100)  * (this->getAttack() + this->attackBuff())) /  (100 + orcs.getDefense())));
    orcs.addHealth(-1 * damage);
    this->addHealth(5);
    
}

void Vampire::attack(Merchant&  merchant){
    //std::cout << "called attack Merchant" << std::endl;
    int damage = std::ceil((((100)  * (this->getAttack() + this->attackBuff())) /  (100 + merchant.getDefense())));
    merchant.addHealth(-1 * damage);
    this->addHealth(5);    
}

void Vampire::attack(Halfling& halfling){
    //std::cout << "called attack Halfling" << std::endl;
    int damage = std::ceil((((100)  * (this->getAttack() + this->attackBuff())) /  (100 + halfling.getDefense())));
    int randomAttack = rand() % 2;
    if(randomAttack == 0){
        halfling.addHealth(-1 * damage);
        this->addHealth(5);
    }
}

void Vampire::attack(Dragon& dragon){
    //std::cout << "called attack dragon" << std::endl;
    int damage = std::ceil((((100)  * (this->getAttack() + this->attackBuff())) /  (100 + dragon.getDefense())));
    dragon.addHealth(-1 * damage);
    this->addHealth(5);
}


