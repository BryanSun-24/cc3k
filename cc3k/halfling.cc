#include "halfling.h"
#include "player.h"

#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"

Halfling::Halfling(int x, int y, int gold):Enemy{x,y,100,15,20,gold,true} {}

void Halfling::beAttacked(std::shared_ptr<Player>& player){
     std::cout << "called halfling beattack" << std::endl;
    player->attack(*this);
}

void Halfling::attack(Shade& shade){
    int damage = std::ceil((((100)  * (this->getAttack())) /  (100 + shade.getDefense()+ shade.defenseBuff())));
    shade.addHealth(-1 * damage);
}
void Halfling::attack(Drow& drow) {
    int damage = std::ceil((((100)  * (this->getAttack())) /  (100 + drow.getDefense()+ drow.defenseBuff())));
    drow.addHealth(-1 * damage);
}
void Halfling::attack(Vampire& vampire) {
    int damage = std::ceil((((100)  * (this->getAttack())) /  (100 + vampire.getDefense()+ vampire.defenseBuff())));
    vampire.addHealth(-1 * damage);
}
void Halfling::attack(Troll& troll) {
    int damage = std::ceil((((100)  * (this->getAttack())) /  (100 + troll.getDefense()+ troll.defenseBuff())));
    troll.addHealth(-1 * damage);
}
void Halfling::attack(Goblin& goblin) {
    int damage = std::ceil((((100)  * (this->getAttack())) /  (100 + goblin.getDefense()+ goblin.defenseBuff())));
    goblin.addHealth(-1 * damage);
}

