#include "merchant.h"
#include "player.h"

#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"

Merchant::Merchant(int x, int y):Enemy{x,y,30,70,5,-2,"Merchant",true,true,false} {}

void Merchant::beAttacked(std::shared_ptr<Player>& player){
    player->attack(*this);
}

