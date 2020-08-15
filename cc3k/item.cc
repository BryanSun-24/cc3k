#include "item.h"

Item::Item(int x, int y, std::string type, int num):State{x,y},type{type},num{num} {}

std::string Item::getItemType(){
    return this->type;
}
