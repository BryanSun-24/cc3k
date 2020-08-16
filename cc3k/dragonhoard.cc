#include "dragonhoard.h"

DragonHoard::DragonHoard(int x, int y, std::shared_ptr<Player> player):Treasure{x,y,"DragonHoard",6,false,player} {}

void DragonHoard::addGold() {
    this->player->addGold(this->num);
}

void DragonHoard::changePickable(){
    this->pickable = true;
}

