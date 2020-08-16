#include "elf.h"
#include "player.h"

#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"
#include "batman.h"

Elf::Elf(int x, int y, int gold):Enemy{x,y,140,30,10,gold,"Elf",true,true,true}{}

void Elf::beAttacked(std::shared_ptr<Player>& player){
    player->attack(*this);
}


void Elf::attack(Shade& shade){
    for(int i = 0; i < 2; ++i){
        int randomAttack = rand() % 2;
        int damage = std::ceil((((100)  * (this->getAttack())) /  (100 + shade.getDefense()+ shade.defenseBuff())));
        if(randomAttack == 0){
            shade.addHealth(-1 * damage);
        }
    }
}

void Elf::attack(Vampire& vampire) {
    for(int i = 0; i < 2; ++i){
        int randomAttack = rand() % 2;
        int damage = std::ceil((((100)  * (this->getAttack())) /  (100 + vampire.getDefense()+ vampire.defenseBuff())));
        if(randomAttack == 0){
            vampire.addHealth(-1 * damage);
        }
    }
}

void Elf::attack(Troll& troll) {
    for(int i = 0; i < 2; ++i){
        int randomAttack = rand() % 2;
        int damage = std::ceil((((100)  * (this->getAttack())) /  (100 + troll.getDefense()+ troll.defenseBuff())));
        if(randomAttack == 0){
            troll.addHealth(-1 * damage);
        }
    }
}

void Elf::attack(Goblin& goblin) {
    for(int i = 0; i < 2; ++i){
        int randomAttack = rand() % 2;
        int damage = std::ceil((((100)  * (this->getAttack())) /  (100 + goblin.getDefense()+ goblin.defenseBuff())));
        if(randomAttack == 0){
            goblin.addHealth(-1 * damage);
        }
    }
}

void Elf::attack(Batman& batman) {
    for(int i = 0; i < 2; ++i){
        int randomAttack = rand() % 2;
        int damage = std::ceil((((100)  * (this->getAttack())) /  (100 + batman.getDefense()+ batman.defenseBuff())));
        if(randomAttack == 0){
            batman.addHealth(-1 * damage);
        }
    }
}


