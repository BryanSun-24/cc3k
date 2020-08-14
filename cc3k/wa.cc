#include "wa.h"

WA::WA(int x, int y, std::shared_ptr<Buff> buff):Potion{x,y,-5,buff}{}

void WA::addBuff(){
    this->buff->attackPotion(this->num);
}
