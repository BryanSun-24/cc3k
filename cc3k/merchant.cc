#include "merchant.h"
#include "player.h"

#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"

Merchant::Merchant(int x, int y):Enemy{x,y,30,70,5,-2, true} {}

void Merchant::beAttacked(std::shared_ptr<Player>& player){
     std::cout << "called merchant beattack" << std::endl;
    player->attack(*this);
}

void Merchant::attack(Shade& shade){
    int damage = std::ceil((((100)  * (this->getAttack())) /  (100 + shade.getDefense()+ shade.defenseBuff())));
    shade.addHealth(-1 * damage);
}
void Merchant::attack(Drow& drow) {
    int damage = std::ceil((((100)  * (this->getAttack())) /  (100 + drow.getDefense()+ drow.defenseBuff())));
    drow.addHealth(-1 * damage);
}
void Merchant::attack(Vampire& vampire) {
    int damage = std::ceil((((100)  * (this->getAttack())) /  (100 + vampire.getDefense()+ vampire.defenseBuff())));
    vampire.addHealth(-1 * damage);
}
void Merchant::attack(Troll& troll) {
    int damage = std::ceil((((100)  * (this->getAttack())) /  (100 + troll.getDefense()+ troll.defenseBuff())));
    troll.addHealth(-1 * damage);
}
void Merchant::attack(Goblin& goblin) {
    int damage = std::ceil((((100)  * (this->getAttack())) /  (100 + goblin.getDefense()+ goblin.defenseBuff())));
    goblin.addHealth(-1 * damage);
}

