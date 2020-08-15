#include "enemy.h"
#include "player.h"
#include <cstdlib>
using namespace std;

Enemy::Enemy(int x, int y, int health, int attack, int defense, int gold, bool moveAble):Character{x,y,health,attack,defense,gold}, moveAble{moveAble} {}

bool Enemy::checkPlayer(int row, int col){
    return ((abs(this->getRow()-row) <= 1) && (abs(this->getCol()-col) <= 1));
}

bool Enemy::isMovable(){
    return this->moveAble;
}

