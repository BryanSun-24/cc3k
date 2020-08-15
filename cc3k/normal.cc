#include "normal.h"

Normal::Normal(int x, int y, std::shared_ptr<Player> player):Treasure{x,y,2,true,player} {}

void Normal::addGold() {
    //std::cout << "called pick Normal" << std::endl;
    this->player->addGold(this->num);
}

