#include "orcs.h"
#include "player.h"

#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"

Orcs::Orcs(int x, int y, int gold):Enemy{x,y,180,30,25,gold,true}{}


void Orcs::beAttacked(std::shared_ptr<Player>& player){
    std::cout << "called orcs beattack" << std::endl;
    player->attack(*this);
}

void Orcs::attack(Shade& shade){
    int damage = std::ceil((((100)  * (this->getAttack())) /  (100 + shade.getDefense()+ shade.defenseBuff())));
    shade.addHealth(-1 * damage);
}
void Orcs::attack(Drow& drow) {
    int damage = std::ceil((((100)  * (this->getAttack())) /  (100 + drow.getDefense()+ drow.defenseBuff())));
    drow.addHealth(-1 * damage);
}
void Orcs::attack(Vampire& vampire) {
    int damage = std::ceil((((100)  * (this->getAttack())) /  (100 + vampire.getDefense()+ vampire.defenseBuff())));
    vampire.addHealth(-1 * damage);
}
void Orcs::attack(Troll& troll) {
    int damage = std::ceil((((100)  * (this->getAttack())) /  (100 + troll.getDefense()+ troll.defenseBuff())));
    troll.addHealth(-1 * damage);
}
void Orcs::attack(Goblin& goblin) {
    int damage = std::ceil((((100)  * (this->getAttack())) /  (100 + goblin.getDefense()+ goblin.defenseBuff())) * 1.5);
    goblin.addHealth(-1 * damage);
}
