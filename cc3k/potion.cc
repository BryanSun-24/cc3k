#include "potion.h"

using namespace std;

Potion::Potion(int x, int y, std::string type, int num, std::shared_ptr<Buff> buff):Item{x,y,type,num},buff{buff} {}

int Potion::getEffect(){
    return this->num;
}
