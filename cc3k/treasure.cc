#include "treasure.h"

using namespace std;

Treasure::Treasure(int x, int y, std::string type, int num, bool pickable, std::shared_ptr<Player> player):Item{x,y,type,num}, pickable{pickable}, player{player} {}

int Treasure::getGold(){
    return this->num;
}

bool Treasure::isPickable(){
    return this->pickable;
}

