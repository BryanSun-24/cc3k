#include "small.h"

Small::Small(int x, int y, std::shared_ptr<Player> player):Treasure{x,y,1,true,player} {}

void Small::addGold(){
    //std::cout << "called pick Small" << std::endl;
    this->player->addGold(this->num);
}

