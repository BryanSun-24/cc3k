#include "floor.h"
#include "textdisplay.h"
#include <fstream>
#include <memory>
#include <iomanip>
#include <algorithm>
#include "rh.h"
#include "ph.h"
#include "ba.h"
#include "wa.h"
#include "bd.h"
#include "wd.h"
#include "normal.h"
#include "small.h"
#include "merchanhoard.h"
#include "dragonhoard.h"

#include "human.h"
#include "dwarf.h"
#include "halfling.h"
#include "elf.h"
#include "orcs.h"
#include "merchant.h"


Floor::Floor(int num):floorNum{num} {}

void Floor::init(){
    this->textdisplay = std::make_unique<Textdisplay>(25,81);
}

void Floor::print(){
    this->textdisplay->print();
    std::cout << std::setw(77) << "floor " << this->floorNum << std::endl;
    std::cout << "attackbuff: " << this->player->attackBuff() << " attack: " << this->player->getAttack() << "\n";
    std::cout << "defensebuff: " << this->player->defenseBuff() << " defense: " << this->player->getDefense() << "\n";
    std::cout << "gold: " << this->player->getGold() << std::endl;
    //std::cout << "healthbuff: " << this->player->healthBuff() << "health: " << this->player->getHealth() << "\n";
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
     for(int i = 0; i< 20; ++i){
        std::vector<int> Pos = this->generateValidPos();
        int randomEnemy = rand() % 18;
        if(randomEnemy >= 0 && randomEnemy <= 1){
            this->enemies.emplace_back(std::make_shared<Human>(Pos[0],Pos[1]));
            this->textdisplay->setHuman(Pos[0],Pos[1]);
        } else if(randomEnemy >= 2 && randomEnemy <= 4){
            int randGold = rand() % 2 + 1;
            this->enemies.emplace_back(std::make_shared<Dwarf>(Pos[0],Pos[1],randGold));
            this->textdisplay->setDwarf(Pos[0],Pos[1]);
        }
        else if(randomEnemy >= 5 && randomEnemy <= 9){
            int randGold = rand() % 2 + 1;
            this->enemies.emplace_back(std::make_shared<Elf>(Pos[0],Pos[1],randGold));
            this->textdisplay->setElf(Pos[0],Pos[1]);
        }
        else if(randomEnemy == 10){
            int randGold = rand() % 2 + 1;
            this->enemies.emplace_back(std::make_shared<Orcs>(Pos[0],Pos[1],randGold));
            this->textdisplay->setOrcs(Pos[0],Pos[1]);
        }
        else if(randomEnemy == 11){
            this->enemies.emplace_back(std::make_shared<Merchant>(Pos[0],Pos[1]));
            this->textdisplay->setMerchant(Pos[0],Pos[1]); 
        }
        else if(randomEnemy == 12){
            int randGold = rand() % 2 + 1;
            this->enemies.emplace_back(std::make_shared<Halfling>(Pos[0],Pos[1],randGold));
            this->textdisplay->setHalfling(Pos[0],Pos[1]);
        } else {
            continue;
        }
    }

}

void Floor::setPlayer(std::shared_ptr<Player> player){
    this->player = player;
}

void Floor::setStairs(){
    std::vector<int> Pos = this->generateValidPos();
    this->textdisplay->setStairs(Pos[0],Pos[1]);
}

std::vector<int> Floor::generateValidPos(){
    int size = this->chambers.size();
    std::vector<int> Pos;
    while(true){
        int randomChamber = rand() % size;
        Pos = this->chambers[randomChamber]->generateChamberPos();
        if(this->textdisplay->checkEmpty(Pos[0],Pos[1])){
            return Pos;
        }
    }  
}

void Floor::setTreasures(){
    for(int i = 0; i< 10; ++i){
        std::vector<int> Pos = this->generateValidPos();
        int randomGold = rand() % 7;
        if(randomGold >= 0 && randomGold <= 4){
            this->treasures.emplace_back(std::make_shared<Normal>(Pos[0],Pos[1], this->player));
            this->textdisplay->setGold(Pos[0],Pos[1]);
        } else if(randomGold >= 5 && randomGold <= 6){
            this->treasures.emplace_back(std::make_shared<Small>(Pos[0],Pos[1], this->player));
            this->textdisplay->setGold(Pos[0],Pos[1]);
        }
        else {
            this->treasures.emplace_back(std::make_shared<DragonHoard>(Pos[0],Pos[1], this->player));
            this->textdisplay->setGold(Pos[0],Pos[1]);
        }
    }
}

void Floor::setPotions(){
    for(int i = 0; i< 10; ++i){
        std::vector<int> Pos = this->generateValidPos();
        int randomPotion = rand() % 6;
        if(randomPotion == 0){
            this->potions.emplace_back(std::make_shared<RH>(Pos[0],Pos[1],this->player->getBuff()));
            this->textdisplay->setPotion(Pos[0],Pos[1]);
        } else if(randomPotion == 1){
            this->potions.emplace_back(std::make_shared<PH>(Pos[0],Pos[1],this->player->getBuff()));
            this->textdisplay->setPotion(Pos[0],Pos[1]);
        }
        else if(randomPotion == 2){
            this->potions.emplace_back(std::make_shared<BA>(Pos[0],Pos[1],this->player->getBuff()));
            this->textdisplay->setPotion(Pos[0],Pos[1]);
        }
        else if(randomPotion == 3){
            this->potions.emplace_back(std::make_shared<WA>(Pos[0],Pos[1],this->player->getBuff()));
            this->textdisplay->setPotion(Pos[0],Pos[1]);
        }
        else if(randomPotion == 4){
            this->potions.emplace_back(std::make_shared<BD>(Pos[0],Pos[1],this->player->getBuff()));
            this->textdisplay->setPotion(Pos[0],Pos[1]); 
        }
        else if(randomPotion == 5){
            this->potions.emplace_back(std::make_shared<WD>(Pos[0],Pos[1],this->player->getBuff()));
            this->textdisplay->setPotion(Pos[0],Pos[1]);
        }
    }
}

char Floor::movePlayer(std::string direction, std::string command) {
    bool valid;
    char symbol;
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

    if(command == "normal"){
        valid = this->textdisplay->validMove(nextRow, nextCol);
    }
    if(command == "potion"){
        valid = this->textdisplay->validMovePotion(nextRow, nextCol);
    }
    
    if(valid){
        if(this->textdisplay->checkStair(nextRow,nextCol)){
            return '\\';
        }
        this->player->setPos(nextRow,nextCol);
        this->textdisplay->setSymbol(curRow, curCol);
        this->textdisplay->updateSymbol(nextRow, nextCol);
        symbol = this->textdisplay->getSymbol(nextRow,nextCol);
        this->textdisplay->setPlayer(nextRow,nextCol);
    } else {
        std::cerr << "you can't go" << std::endl;
    }
    return symbol;
}

void Floor::pickPotion(int row, int col){
    auto it = std::find_if(this->potions.begin(), this->potions.end(), [&row, &col](std::shared_ptr<Potion>& potion) { return (potion->getRow() == row)&&(potion->getCol() == col); });
    (*it)->addBuff();
}

void Floor::pickGold(int row, int col){
    //std::cout << "called pickGold" << std::endl;
    auto it = std::find_if(this->treasures.begin(), this->treasures.end(), [&row, &col](std::shared_ptr<Treasure>& treasure) { return (treasure->getRow() == row)&&(treasure->getCol() == col); });
    (*it)->addGold();
}

