#include "orcs.h"
#include "player.h"

#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"

Orcs::Orcs(int x, int y, int gold):Enemy{x,y,180,30,25,gold,true,true}{}


void Orcs::beAttacked(std::shared_ptr<Player>& player){
    std::cout << "called orcs beattack" << std::endl;
    player->attack(*this);
}

void Orcs::attack(Goblin& goblin) {
    int randomAttack = rand() % 2;
    int damage = std::ceil((((100)  * (this->getAttack())) /  (100 + goblin.getDefense()+ goblin.defenseBuff())) * 1.5);
    if(randomAttack == 0){
        goblin.addHealth(-1 * damage);
    }
}

