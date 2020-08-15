#include "state.h"

State::State(int x, int y):x{x},y{y} {}

int State::getRow(){
    return this->x;
}

int State::getCol(){
    return this->y;
}

void State::setPos(int x, int y){
    this->x = x;
    this->y = y;
}

