#include "potion.h"

using namespace std;

Potion::Potion(int x, int y, int num, std::shared_ptr<Buff> buff):Item{x,y,num},buff{buff} {}

int Potion::getEffect(){
    return this->num;
}
