#include "dwarf.h"
#include "player.h"

#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"

Dwarf::Dwarf(int x, int y, int gold):Enemy{x,y,100,20,30,gold,true,true} {}

void Dwarf::beAttacked(std::shared_ptr<Player>& player){
    std::cout << "called dwarf beattack" << std::endl;
    player->attack(*this);
}
