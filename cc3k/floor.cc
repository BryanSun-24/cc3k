#include "floor.h"
#include "textdisplay.h"
#include <fstream>
#include <memory>

Floor::Floor(int num):floorNum{num}{
}

void Floor::init(){
    this->textdisplay = std::make_unique<Textdisplay>(25,81);
}

void Floor::print(){
    this->textdisplay->print();
}

void Floor::setChamber(){

}

void Floor::setEnemies(){

}

void Floor::setPlayer(std::shared_ptr<Player> player){
    this->player = player;
}

void Floor::setTreasure(){

}

void Floor::setPotion(){

}

void Floor::setDisplay(){

}

