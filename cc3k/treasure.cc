#include "treasure.h"

using namespace std;

Treasure::Treasure(int x, int y, int num, bool pickable, std::shared_ptr<Player> player):Item{x,y,num}, player{player}, pickable{pickable} {}

int Treasure::getGold(){
    return this->num;
}

bool Treasure::isPickable(){
    return this->pickable;
}
