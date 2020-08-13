#include "rh.h"

RH::RH(int x, int y, std::shared_ptr<Buff> buff):Potion{x,y,10,buff}{}

void RH::addBuff(){
    this->buff->healthPotion(10);
}
