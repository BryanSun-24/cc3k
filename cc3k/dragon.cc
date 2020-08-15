#include "dragon.h"
#include "player.h"

#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"

Dragon::Dragon(int x, int y, std::shared_ptr<DragonHoard> dragonHoard):Enemy{x,y,150,20,20,0,false},dragonHoard{dragonHoard}{}

void Dragon::beAttacked(std::shared_ptr<Player>& player){
    player->attack(*this);
}

void Dragon::attack(Shade& shade){
    int damage = std::ceil((((100)  * (this->getAttack())) /  (100 + shade.getDefense()+ shade.defenseBuff())));
    shade.addHealth(-1 * damage);
}
void Dragon::attack(Drow& drow) {
    int damage = std::ceil((((100)  * (this->getAttack())) /  (100 + drow.getDefense()+ drow.defenseBuff())));
    drow.addHealth(-1 * damage);
}
void Dragon::attack(Vampire& vampire) {
    int damage = std::ceil((((100)  * (this->getAttack())) /  (100 + vampire.getDefense()+ vampire.defenseBuff())));
    vampire.addHealth(-1 * damage);
}
void Dragon::attack(Troll& troll) {
    int damage = std::ceil((((100)  * (this->getAttack())) /  (100 + troll.getDefense()+ troll.defenseBuff())));
    troll.addHealth(-1 * damage);
}
void Dragon::attack(Goblin& goblin) {
    int damage = std::ceil((((100)  * (this->getAttack())) /  (100 + goblin.getDefense()+ goblin.defenseBuff())));
    goblin.addHealth(-1 * damage);
}

void Dragon::setGoldPickable(){
    this->dragonHoard->changePickable();
}

bool Dragon::checkPlayer(int row, int col){
    bool check1 = ((abs(this->getRow()-row) <= 1) && (abs(this->getCol()-col) <= 1));
    bool check2 = ((abs(this->dragonHoard->getRow()-row) <= 1) && (abs(this->dragonHoard->getCol()-col) <= 1));
     return (check1 || check2);
}

