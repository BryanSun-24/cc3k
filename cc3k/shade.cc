#include "shade.h"
#include "enemy.h"

Shade::Shade(int x, int y, std::shared_ptr<Buff> buff):Player{x,y,125,25,25,0,125,buff} {}

void Shade::beAttacked(std::shared_ptr<Enemy>& enemy) {
    enemy->attack(*this);
}

