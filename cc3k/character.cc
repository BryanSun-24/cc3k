#include "character.h"

using namespace std;

Character::Character(int x, int y, int health, int attack, int defense, int gold):State{x,y},health{health},attack{attack},defense{defense},gold{gold},isAlive{true}{}

