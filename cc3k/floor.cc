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
#include "dragon.h"

#include "moveException.h"
#include "pickException.h"
#include "walkException.h"
#include "potionException.h"
#include "attackException.h"


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
    this->textdisplay->setCharacter(Pos[0],Pos[1], '@');
    //std::cout << "random pos x: " << Pos[0] << "y: " << Pos[1] << std::endl;
}

void Floor::setEnemies(){
     for(int i = 0; i< 20; ++i){
        std::vector<int> Pos = this->generateValidPos();
        int randomEnemy = rand() % 18;
        if(randomEnemy >= 0 && randomEnemy <= 3){
            this->enemies.emplace_back(std::make_shared<Human>(Pos[0],Pos[1]));
            this->textdisplay->setHuman(Pos[0],Pos[1]);
        } else if(randomEnemy >= 4 && randomEnemy <= 6){
            int randGold = rand() % 2 + 1;
            this->enemies.emplace_back(std::make_shared<Dwarf>(Pos[0],Pos[1],randGold));
            this->textdisplay->setDwarf(Pos[0],Pos[1]);
        }
        else if(randomEnemy >= 7 && randomEnemy <= 11){
            int randGold = rand() % 2 + 1;
            this->enemies.emplace_back(std::make_shared<Elf>(Pos[0],Pos[1],randGold));
            this->textdisplay->setElf(Pos[0],Pos[1]);
        }
        else if(randomEnemy >= 12 && randomEnemy <= 13){
            int randGold = rand() % 2 + 1;
            this->enemies.emplace_back(std::make_shared<Orcs>(Pos[0],Pos[1],randGold));
            this->textdisplay->setOrcs(Pos[0],Pos[1]);
        }
        else if(randomEnemy >= 14 && randomEnemy <= 15){
            this->enemies.emplace_back(std::make_shared<Merchant>(Pos[0],Pos[1]));
            this->textdisplay->setMerchant(Pos[0],Pos[1]); 
        }
        else {
            int randGold = rand() % 2 + 1;
            this->enemies.emplace_back(std::make_shared<Halfling>(Pos[0],Pos[1],randGold));
            this->textdisplay->setHalfling(Pos[0],Pos[1]);
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
        int randomGold = rand() % 8;
        if(randomGold >= 0 && randomGold <= 4){
            this->treasures.emplace_back(std::make_shared<Normal>(Pos[0],Pos[1], this->player));
            this->textdisplay->setGold(Pos[0],Pos[1]);
        } else if(randomGold >= 5 && randomGold <= 6){
            this->treasures.emplace_back(std::make_shared<Small>(Pos[0],Pos[1], this->player));
            this->textdisplay->setGold(Pos[0],Pos[1]);
        }
        else {
            auto dragonhoard = std::make_shared<DragonHoard>(Pos[0],Pos[1], this->player);
            this->treasures.emplace_back(dragonhoard);
            this->textdisplay->setGold(Pos[0],Pos[1]);
            for(int j = 0; j < 8; j++){
                std::vector<int> pos = getPos(Pos[0],Pos[1], "nothing", j);
                if(this->textdisplay->checkEmpty(pos[0], pos[1])){
                    this->enemies.emplace_back(std::make_shared<Dragon>(pos[0],pos[1],dragonhoard));
                    this->textdisplay->setCharacter(pos[0],pos[1],'D');
                    break;
                }
            }
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

std::vector<int> Floor::getPos(int x, int y, std::string direction, int direc){
    std::vector<std::string> listofDirec = {"no","so","ea","we","ne","se","sw","nw"};
    if(direc > -1){
        direction = listofDirec[direc];
    }
    std::vector<int> newPos;
    int nextRow = x;
    int nextCol = y;
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
        throw MoveException();
    }
    newPos.emplace_back(nextRow);
    newPos.emplace_back(nextCol);
    return newPos;
}


char Floor::getSymbol(std::string direction) {
    int curRow = this->player->getRow();
    int curCol = this->player->getCol();
    std::vector<int> newPos = getPos(curRow, curCol, direction, -1);

    return this->textdisplay->getSymbol(newPos[0],newPos[1]);
}

void Floor::movePlayer(std::string direction, std::string command) {
    
    bool valid;
    char symbol;
    int curRow = this->player->getRow();
    int curCol = this->player->getCol();

    std::vector<int> newPos = getPos(curRow, curCol, direction, -1);

    int nextRow = newPos[0];
    int nextCol = newPos[1];

    if(command == "normal"){
        valid = this->textdisplay->validMove(nextRow, nextCol);
        if(!valid){ throw WalkException(); }
    }
    if(command == "potion"){
        valid = this->textdisplay->validMovePotion(nextRow, nextCol);
        if(!valid){ throw PotionException(); }
    }
    /*if(command == "attack"){
        valid = this->textdisplay->validAttackEnemy(nextRow, nextCol);
        if(!valid){ throw AttackException(); }
    }*/
    
    if(valid){
        //if(this->textdisplay->checkStair(nextRow,nextCol)){
            //return '\\';
        //}
        this->player->setPos(nextRow,nextCol);
        this->textdisplay->setSymbol(curRow, curCol);
        this->textdisplay->updateSymbol(nextRow, nextCol);
        this->textdisplay->setCharacter(nextRow,nextCol,'@');
    }
}

void Floor::attackPlayerOrMoveEnemies(){
    for (int i = 0; i < this->enemies.size(); i++){
        if (enemies[i]->checkPlayer(this->player->getRow(), this->player->getCol())){
            std::cout << "My health before : " << this->player->getHealth() << "\n";
            this->player->beAttacked(enemies[i]);
             std::cout << "My health after : " << this->player->getHealth() << "\n";
            if(!this->player->isAlive()){
                std::cout << "You are died" << std::endl;
            }
        }else{
            bool enemyMovable = false;
            for(int j = 0; j < 8; j++){
                std::vector<int> Pos = getPos(this->enemies[i]->getRow(), this->enemies[i]->getCol(), "nothing", j);
                if(this->textdisplay->checkEmpty(Pos[0], Pos[1])){
                    enemyMovable = true;
                    break;
                }
            }
            while(enemyMovable && enemies[i]->isMovable()){
                int randomDirection = rand() % 8;
                std::vector<int> Pos = getPos(this->enemies[i]->getRow(), this->enemies[i]->getCol(), "nothing", randomDirection);
                if(this->textdisplay->checkEmpty(Pos[0], Pos[1])){
                    char current = this->textdisplay->getSymbol(this->enemies[i]->getRow(), this->enemies[i]->getCol());
                    this->textdisplay->setCharacter(Pos[0],Pos[1],current);
                    this->textdisplay->setCharacter(this->enemies[i]->getRow(), this->enemies[i]->getCol(),'.');
                    this->enemies[i]->setPos(Pos[0], Pos[1]);
                    break;
                }
            }
        }
    }
}

void Floor::attackEnemy(int row, int col){
    //std::cout << "called attackEnemy" << std::endl;
    auto it = std::find_if(this->enemies.begin(), this->enemies.end(), [&row, &col](std::shared_ptr<Enemy>& enemies) { return (enemies->getRow() == row)&&(enemies->getCol() == col); });
    //std::cout << "auto find" << std::endl;
    if(it != this->enemies.end()){
        std::cout << "enemy health before : " << (*it)->getHealth() << "\n";
        (*it)->beAttacked(this->player);
        std::cout << "enemy health after : " << (*it)->getHealth() << "\n";
        if(!(*it)->isAlive()){
            int reward = (*it)->getGold();
            if(reward < 0){
                this->textdisplay->setCharacter((*it)->getRow(),(*it)->getCol(),'G');
                if(reward == -1){
                    this->treasures.emplace_back(std::make_shared<Normal>((*it)->getRow(),(*it)->getCol(), this->player));
                    for(int j = 0; j < 8; j++){
                        std::vector<int> Pos = getPos((*it)->getRow(), (*it)->getCol(), "nothing", j);
                        if(this->textdisplay->checkEmpty(Pos[0], Pos[1])){
                            this->treasures.emplace_back(std::make_shared<Normal>(Pos[0],Pos[1], this->player));
                            this->textdisplay->setCharacter(Pos[0],Pos[1],'G');
                            break;
                        }
                    }
                }
                if(reward == -2){
                    this->treasures.emplace_back(std::make_shared<MerchanHoard>((*it)->getRow(),(*it)->getCol(), this->player));
                }
            } else if(reward == 0){
                (*it)->setGoldPickable();
                this->textdisplay->setCharacter((*it)->getRow(),(*it)->getCol(),'.');
            } else {
                this->player->addGold(reward);
                this->textdisplay->setCharacter((*it)->getRow(),(*it)->getCol(),'.');
            }
            this->enemies.erase(it);
            std::cout << "Enemies has been slained" << std::endl;
        }
    } else {
        throw AttackException();
    }
}

void Floor::pickPotion(int row, int col){
    auto it = std::find_if(this->potions.begin(), this->potions.end(), [&row, &col](std::shared_ptr<Potion>& potion) { return (potion->getRow() == row)&&(potion->getCol() == col); });
    (*it)->addBuff();
    this->potions.erase(it);
}

void Floor::pickGold(std::string direction){
    int curRow = this->player->getRow();
    int curCol = this->player->getCol();
    std::vector<int> newPos = getPos(curRow, curCol, direction, -1);
    int row = newPos[0];
    int col = newPos[1];
    //std::cout << "called pickGold" << std::endl;
    auto it = std::find_if(this->treasures.begin(), this->treasures.end(), [&row, &col](std::shared_ptr<Treasure>& treasure) { return (treasure->getRow() == row)&&(treasure->getCol() == col); });
    if((*it)->isPickable()){
        (*it)->addGold();
        this->treasures.erase(it);
    } else {
        throw PickException();
    }
    
}

