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
        this->chambers.emplace_back(std::make_shared<Chamber>(i+1));
    }
}

void Floor::randomPlayer(){
    int size = this->chambers.size();
    //std::cout << "size: " << size << std::endl;
    int randomChamber = rand() % size;
    std::vector<int> Pos;
    Pos = this->chambers[randomChamber]->generateChamberPos();
    this->player->setPos(Pos[0],Pos[1]);
    this->textdisplay->setPlayer(Pos[0],Pos[1]);
    //std::cout << "random pos x: " << Pos[0] << "y: " << Pos[1] << std::endl;
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
void Floor::movePlayer(std::string direction) {
    int curRow = this->player->getRow();
    int curCol = this->player->getCol();

    int nextRow = curRow;
    int nextCol = curCol;

    if(direction == "no"){
        nextRow -= 1;
        //std::cout << "Action: PC moves North." << std::endl;
    }
    else if(direction == "so"){
        nextRow += 1;
        //std::cout << "Action: PC moves South." << std::endl;
    }
    else if(direction == "ea"){
        nextCol += 1;
        //action = "PC moves to the East.";
    }
    else if(direction == "we"){
        nextCol -= 1;
        //action = "PC moves to the West.";
    }
    else if(direction == "ne"){
        nextRow -= 1;
        nextCol += 1;
        //action = "PC moves to the NorthEast.";
    }
    else if(direction == "se"){
        nextRow += 1;
        nextCol += 1;
        //action = "PC moves to the SouthEast.";
    }
    else if(direction == "sw"){
        nextRow += 1;
        nextCol -= 1;
        //action = "PC moves to the SouthWest.";
    }
    else if(direction == "nw"){
        nextRow -= 1;
        nextCol -= 1;
        //action = "PC moves to the NorthWest.";        
    } else {
        std::cerr << "invalid direction" << std::endl;
    }

    bool valid = this->textdisplay->validMove(nextRow, nextCol);
    if(valid){
        this->player->setPos(nextRow,nextCol);
        this->textdisplay->setEmpty(curRow, curCol);
        this->textdisplay->setPlayer(nextRow,nextCol);
    } else {
        std::cerr << "you can't go" << std::endl;
    }
}

