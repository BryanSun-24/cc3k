#include "ph.h"

PH::PH(int x, int y, std::shared_ptr<Buff> buff):Potion{x,y,-10,buff}{}

void PH::addBuff(){
    this->buff->healthPotion(this->num);
}
