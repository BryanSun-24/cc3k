#include "batman.h"
#include "enemy.h"

Batman::Batman(int x, int y, std::shared_ptr<Buff> buff):Player{x,y,110,35,35,50,"Batman",200,buff} {}

void Batman::beAttacked(std::shared_ptr<Enemy>& enemy) {
    enemy->attack(*this);
}

