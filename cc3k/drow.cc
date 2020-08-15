#include "drow.h"
#include "enemy.h"

Drow::Drow(int x, int y, std::shared_ptr<Buff> buff):Player{x,y,150,25,15,0,"Drow",150,buff} {}

void Drow::beAttacked(std::shared_ptr<Enemy>& enemy) {
    enemy->attack(*this);
}

void Drow::gainHp(){
    this->addHealth(int(this->buff->getHealth()* 1.5));
    if(this->getHealth() > this->maxHp){
        this->setMaxHealth(this->maxHp);
    }
}

int Drow::attackBuff(){
    return int(this->buff->getAttack()*1.5);
} 

int Drow::defenseBuff(){
    return int(this->buff->getDefense()*1.5);
}

