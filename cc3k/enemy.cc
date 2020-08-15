#include "enemy.h"
#include "player.h"
#include <cstdlib>

#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"

using namespace std;

Enemy::Enemy(int x, int y, int health, int attack, int defense, int gold, std::string race, bool moveAble, bool fmoveAble, bool hostile):Character{x,y,health,attack,defense,gold,race}, moveAble{moveAble}, fmoveAble{fmoveAble},  hostile{hostile} {}

bool Enemy::checkPlayer(int row, int col){
    return ((abs(this->getRow()-row) <= 1) && (abs(this->getCol()-col) <= 1));
}

bool Enemy::isMovable(){
    return this->moveAble;
}

bool Enemy::isfMovable(){
    return this->fmoveAble;
}

bool Enemy::isHostile(){
    return this->hostile;
}

void Enemy::attack(Shade& shade){
    int randomAttack = rand() % 2;
    int damage = std::ceil((((100)  * (this->getAttack())) /  (100 + shade.getDefense()+ shade.defenseBuff())));
    if(randomAttack == 0){
        shade.addHealth(-1 * damage);
    }
}
void Enemy::attack(Drow& drow) {
    int randomAttack = rand() % 2;
    int damage = std::ceil((((100)  * (this->getAttack())) /  (100 + drow.getDefense()+ drow.defenseBuff())));
    if(randomAttack == 0){
        drow.addHealth(-1 * damage);
    }
}
void Enemy::attack(Vampire& vampire) {
    int randomAttack = rand() % 2;
    int damage = std::ceil((((100)  * (this->getAttack())) /  (100 + vampire.getDefense()+ vampire.defenseBuff())));
    if(randomAttack == 0){
        vampire.addHealth(-1 * damage);
    }
}
void Enemy::attack(Troll& troll) {
    int randomAttack = rand() % 2;
    int damage = std::ceil((((100)  * (this->getAttack())) /  (100 + troll.getDefense()+ troll.defenseBuff())));
    if(randomAttack == 0){
        troll.addHealth(-1 * damage);
    }
}
void Enemy::attack(Goblin& goblin) {
    int randomAttack = rand() % 2;
    int damage = std::ceil((((100)  * (this->getAttack())) /  (100 + goblin.getDefense()+ goblin.defenseBuff())));
    if(randomAttack == 0){
        goblin.addHealth(-1 * damage);
    }
}

void Enemy::setHostile(){
    this->hostile = true;
}

void Enemy::setPause(){
    this->fmoveAble = !this->fmoveAble;
}


