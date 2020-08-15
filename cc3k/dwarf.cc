#include "dwarf.h"
#include "player.h"

#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"

Dwarf::Dwarf(int x, int y, int gold):Enemy{x,y,100,20,30,gold, true}{}

void Dwarf::beAttacked(std::shared_ptr<Player>& player){
    std::cout << "called dwarf beattack" << std::endl;
    player->attack(*this);
}

void Dwarf::attack(Shade& shade){
    int damage = std::ceil((((100)  * (this->getAttack())) /  (100 + shade.getDefense()+ shade.defenseBuff())));
    shade.addHealth(-1 * damage);
}
void Dwarf::attack(Drow& drow) {
    int damage = std::ceil((((100)  * (this->getAttack())) /  (100 + drow.getDefense()+ drow.defenseBuff())));
    drow.addHealth(-1 * damage);
}
void Dwarf::attack(Vampire& vampire) {
    int damage = std::ceil((((100)  * (this->getAttack())) /  (100 + vampire.getDefense()+ vampire.defenseBuff())));
    vampire.addHealth(-1 * damage);
}
void Dwarf::attack(Troll& troll) {
    int damage = std::ceil((((100)  * (this->getAttack())) /  (100 + troll.getDefense()+ troll.defenseBuff())));
    troll.addHealth(-1 * damage);
}
void Dwarf::attack(Goblin& goblin) {
    int damage = std::ceil((((100)  * (this->getAttack())) /  (100 + goblin.getDefense()+ goblin.defenseBuff())));
    goblin.addHealth(-1 * damage);
}
