#include "wd.h"

WD::WD(int x, int y, std::shared_ptr<Buff> buff):Potion{x,y,"Wound Def",-5,buff}{}

void WD::addBuff(){
    this->buff->defensePotion(this->num);
}
