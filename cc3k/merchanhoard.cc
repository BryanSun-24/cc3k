#include "merchanhoard.h"

MerchanHoard::MerchanHoard(int x, int y, std::shared_ptr<Player> player):Treasure{x,y,4,true,player} {}

void MerchanHoard::addGold() {
    this->player->addGold(this->num);
}

