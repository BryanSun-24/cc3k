#include "superman.h"
#include "player.h"

#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"

Superman::Superman(int x, int y):Enemy{x,y,200,50,90,10,"Superman",true,true,true} {}

void Superman::beAttacked(std::shared_ptr<Player>& player){
    player->attack(*this);
}

void Superman::attack(Shade& shade){
    int randomAttack = rand() % 3;
    int damage = std::ceil((((100)  * (this->getAttack())) /  (100 + shade.getDefense()+ shade.defenseBuff())));
    if(randomAttack == 0){
        shade.addHealth(-1 * damage);
    } 
    if(randomAttack == 1) {
        shade.addHealth(-2 * damage);
    }
}

void Superman::attack(Vampire& vampire) {
    int randomAttack = rand() % 3;
    int damage = std::ceil((((100)  * (this->getAttack())) /  (100 + vampire.getDefense()+ vampire.defenseBuff())));
    if(randomAttack == 0){
        vampire.addHealth(-1 * damage);
    }
    if(randomAttack == 1){
        vampire.addHealth(-2 * damage);
    }
}

void Superman::attack(Troll& troll) {
    int randomAttack = rand() % 3;
    int damage = std::ceil((((100)  * (this->getAttack())) /  (100 + troll.getDefense()+ troll.defenseBuff())));
    if(randomAttack == 0){
        troll.addHealth(-1 * damage);
    }
    if(randomAttack == 1){
        troll.addHealth(-2 * damage);
    }
}

void Superman::attack(Goblin& goblin) {
    int randomAttack = rand() % 3;
    int damage = std::ceil((((100)  * (this->getAttack())) /  (100 + goblin.getDefense()+ goblin.defenseBuff())));
    if(randomAttack == 0){
        goblin.addHealth(-1 * damage);
    }
    if(randomAttack == 1){
        goblin.addHealth(-2 * damage);
    }
}

void Superman::attack(Drow& drow) {
    int randomAttack = rand() % 3;
    int damage = std::ceil((((100)  * (this->getAttack())) /  (100 + drow.getDefense()+ drow.defenseBuff())));
    if(randomAttack == 0){
        drow.addHealth(-1 * damage);
    }
    if(randomAttack == 1){
        drow.addHealth(-2 * damage);
    }
}




