#include "state.h"

using namespace std;

State::State(int x, int y):x{x},y{y} {}

int State::getRow(){
    return this->x;
}

int State::getCol(){
    return this->y;
}

