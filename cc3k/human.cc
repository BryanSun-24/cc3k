#include "human.h"
#include "player.h"

#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"

Human::Human(int x, int y):Enemy{x,y,140,20,20,-1,true,true}{}

void Human::beAttacked(std::shared_ptr<Player>& player){
    std::cout << "called human beattack" << std::endl;
    player->attack(*this);
}

