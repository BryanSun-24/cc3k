#include "bd.h"

BD::BD(int x, int y, std::shared_ptr<Buff> buff):Potion{x,y,"Boost Def",5,buff}{}

void BD::addBuff(){
    this->buff->defensePotion(this->num);
}
