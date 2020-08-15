#include "dragon.h"
#include "player.h"

#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"

Dragon::Dragon(int x, int y, std::shared_ptr<DragonHoard> dragonHoard):Enemy{x,y,150,20,20,0,false,true},dragonHoard{dragonHoard}{}

void Dragon::beAttacked(std::shared_ptr<Player>& player){
    player->attack(*this);
}

void Dragon::setGoldPickable(){
    this->dragonHoard->changePickable();
}

bool Dragon::checkPlayer(int row, int col){
    bool check1 = ((abs(this->getRow()-row) <= 1) && (abs(this->getCol()-col) <= 1));
    bool check2 = ((abs(this->dragonHoard->getRow()-row) <= 1) && (abs(this->dragonHoard->getCol()-col) <= 1));
     return (check1 || check2);
}

