#include "merchant.h"
#include "player.h"

#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"

Merchant::Merchant(int x, int y):Enemy{x,y,30,70,5,-2,true,false} {}

void Merchant::beAttacked(std::shared_ptr<Player>& player){
     std::cout << "called merchant beattack" << std::endl;
    player->attack(*this);
}

