#include "halfling.h"
#include "player.h"

#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"

Halfling::Halfling(int x, int y, int gold):Enemy{x,y,100,15,20,gold,"Halfling",true,true,true} {}

void Halfling::beAttacked(std::shared_ptr<Player>& player){
    player->attack(*this);
}

