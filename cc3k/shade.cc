#include "shade.h"
#include "buff.h"
#include "human.h"
#include "dwarf.h"
#include "elf.h"
#include "orcs.h"
#include "merchant.h"
#include "halfling.h"
#include "dragon.h"



Shade::Shade(int x, int y, std::shared_ptr<Buff> buff):Player{x,y,120,2225,25,0,120,buff} {}

void Shade::specialAbility(){

}

void Shade::beAttacked(std::shared_ptr<Enemy>& enemy) {
    enemy->attack(*this);
}


void Shade::attack(Human& human) {
    std::cout << "called attack human" << std::endl;
    int damage = std::ceil((((100)  * (this->getAttack() + this->attackBuff())) /  (100 + human.getDefense())));
    human.addHealth(-1 * damage);
}

void Shade::attack(Dwarf& dwarf) {
    std::cout << "called attack Dwarf" << std::endl;
    int damage = std::ceil((((100)  * (this->getAttack() + this->attackBuff())) /  (100 + dwarf.getDefense())));
    dwarf.addHealth(-1 * damage);
}

void Shade::attack(Elf&  elf) {
    std::cout << "called attack Elf" << std::endl;
    int damage = std::ceil((((100)  * (this->getAttack() + this->attackBuff())) /  (100 + elf.getDefense())));
    elf.addHealth(-1 * damage);
}

void Shade::attack(Orcs& orcs) {
    std::cout << "called attack Orcs" << std::endl;
    int damage = std::ceil((((100)  * (this->getAttack() + this->attackBuff())) /  (100 + orcs.getDefense())));

    std::cout << "this is calculated damage : " << damage <<"\n";
    orcs.addHealth(-1 * damage);
    
    //Test for attach deduce health:
    std::cout << "the health of orcs in attck method " << orcs.getHealth() << "\n";
}

void Shade::attack(Merchant&  merchant){
    std::cout << "called attack Merchant" << std::endl;
    int damage = std::ceil((((100)  * (this->getAttack() + this->attackBuff())) /  (100 + merchant.getDefense())));
    merchant.addHealth(-1 * damage);
}

void Shade::attack(Halfling& halfling){
    std::cout << "called attack Halfling" << std::endl;
    int damage = std::ceil((((100)  * (this->getAttack() + this->attackBuff())) /  (100 + halfling.getDefense())));
    int randomAttack = rand() % 2;
    if(randomAttack == 0){
        halfling.addHealth(-1 * damage);
    }
}

void Shade::attack(Dragon& dragon){
std::cout << "called attack dragon" << std::endl;
    int damage = std::ceil((((100)  * (this->getAttack() + this->attackBuff())) /  (100 + dragon.getDefense())));
    dragon.addHealth(-1 * damage);
}

