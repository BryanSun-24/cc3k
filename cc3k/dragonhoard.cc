#include "dragonhoard.h"

DragonHoard::DragonHoard(int x, int y, std::shared_ptr<Player> player):Treasure{x,y,6,player} {}

void DragonHoard::addGold() {
    //std::cout << "called pick Dragon Gold" << std::endl;
    this->player->addGold(this->num);
}

