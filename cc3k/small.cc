#include "small.h"

Small::Small(int x, int y, std::shared_ptr<Player> player):Treasure{x,y,"Small pile",1,true,player} {}

void Small::addGold(){
    this->player->addGold(this->num);
}

