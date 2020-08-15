#include "human.h"
#include "player.h"

#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"

Human::Human(int x, int y):Enemy{x,y,140,20,20,-1,"Human",true,true,true}{}

void Human::beAttacked(std::shared_ptr<Player>& player){
    player->attack(*this);
}

