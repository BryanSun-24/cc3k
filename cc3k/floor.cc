#include "floor.h"
#include "textdisplay.h"
#include <fstream>
#include <memory>

Floor::Floor(int num):floorNum{num} {}

void Floor::init(){
    this->textdisplay = std::make_unique<Textdisplay>(25,81);
}

void Floor::print(){
    this->textdisplay->print();
}

void Floor::setChambers(){
    for(int i = 0;i < 5; ++i){
        this->chambers.emplaceback(std::make_shared<Chamber>(i));
    }
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

