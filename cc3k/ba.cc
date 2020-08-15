#include "ba.h"

BA::BA(int x, int y, std::shared_ptr<Buff> buff):Potion{x,y,"Boost Atk",5,buff}{}

void BA::addBuff(){
    this->buff->attackPotion(this->num);
}
