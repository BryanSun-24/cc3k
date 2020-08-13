#include "treasure.h"

using namespace std;

Treasure::Treasure(int x, int y, int num, std::shared_ptr<Player> player):Item{x,y,num}, player{player} {}

int Treasure::getGold(){
    return this->num;
}

