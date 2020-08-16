#include <fstream>
#include <memory>
#include <iomanip>
#include <algorithm>
#include <unistd.h>

#include "floor.h"
#include "textdisplay.h"
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
#include "superman.h"

#include "moveException.h"
#include "pickException.h"
#include "walkException.h"
#include "potionException.h"
#include "attackException.h"
#include "dieException.h"


Floor::Floor(int num):floorNum{num},action{"Player Character has spawned"} {}

void Floor::readMap(std::string map, int row){
    std::cout << "called readMap" << std::endl;
    std::cout << "map: " << map << std::endl;
    std::cout << "row: " << row << std::endl;
    std::ifstream in{map};
    std::string line;
    for(int i = 0; i < row; ++i) { getline(in, line); }

    for(int i = 0; i < 25; ++i){
        getline(in, line);
        for(int j = 0; j < 81; ++j){
            this->textdisplay->setCharacter(i,j,line[j]);
        }
    }

    for(int i = 0; i < 25; ++i ){
        for(int j = 0; j < 81; ++j){
            int randGold = rand() % 2 + 1;
            int symbol = this->textdisplay->getSymbol(i,j);
            if (symbol == '0') {
                this->potions.emplace_back(std::make_shared<RH>(i,j,this->player->getBuff()));
                this->textdisplay->setCharacter(i,j,'P');
            }
            else if (symbol == '1'){
                this->potions.emplace_back(std::make_shared<BA>(i,j,this->player->getBuff()));
                this->textdisplay->setCharacter(i,j,'P');
            }
            else if (symbol == '2'){
                this->potions.emplace_back(std::make_shared<BD>(i,j,this->player->getBuff()));
                this->textdisplay->setCharacter(i,j,'P');
            }
            else if (symbol == '3'){
                this->potions.emplace_back(std::make_shared<PH>(i,j,this->player->getBuff()));
                this->textdisplay->setCharacter(i,j,'P');
            }
            else if (symbol == '4'){
                this->potions.emplace_back(std::make_shared<WA>(i,j,this->player->getBuff()));
                this->textdisplay->setCharacter(i,j,'P');
            }
            else if (symbol== '5'){
                this->potions.emplace_back(std::make_shared<WD>(i,j,this->player->getBuff()));
                this->textdisplay->setCharacter(i,j,'P');
            }
            else if (symbol == '6'){
                this->treasures.emplace_back(std::make_shared<Normal>(i,j,this->player));
                this->textdisplay->setCharacter(i,j,'G');
            }
            else if (symbol == '7'){
                this->treasures.emplace_back(std::make_shared<Small>(i,j,this->player));
                this->textdisplay->setCharacter(i,j,'G');
            }
            else if (symbol == '8'){
                this->treasures.emplace_back(std::make_shared<MerchanHoard>(i,j,this->player));
                this->textdisplay->setCharacter(i,j,'G');
            }
            else if (symbol == '9'){
                auto dragonhoard = std::make_shared<DragonHoard>(i,j, this->player);
                this->treasures.emplace_back(dragonhoard);
                this->textdisplay->setCharacter(i,j,'G');
                for(int k = 0; k < 8; k++){
                    std::vector<int> pos = getPos(i,j, "nothing", k);
                    if(this->textdisplay->getSymbol(pos[0], pos[1]) == 'D'){
                        this->enemies.emplace_back(std::make_shared<Dragon>(pos[0],pos[1],dragonhoard));
                        this->textdisplay->setCharacter(pos[0],pos[1],'D');
                        break;
                    }
                }
            }
            else if (symbol == 'H'){
                this->enemies.emplace_back(std::make_shared<Human>(i,j));
                this->textdisplay->setCharacter(i,j,'H');
            }
            else if (symbol == 'M'){
                this->enemies.emplace_back(std::make_shared<Merchant>(i,j));
                this->textdisplay->setCharacter(i,j,'M');
            }
            else if (symbol == 'W'){
                this->enemies.emplace_back(std::make_shared<Dwarf>(i,j,randGold));
                this->textdisplay->setCharacter(i,j,'W');
            }
            else if (symbol == 'E'){
                this->enemies.emplace_back(std::make_shared<Elf>(i,j,randGold));
                this->textdisplay->setCharacter(i,j,'E');
            }
            else if (symbol == 'O'){
                this->enemies.emplace_back(std::make_shared<Orcs>(i,j,randGold));
                this->textdisplay->setCharacter(i,j,'O');
            }
            else if (symbol == 'L'){
                this->enemies.emplace_back(std::make_shared<Halfling>(i,j,randGold));
                this->textdisplay->setCharacter(i,j,'L');
            }
            else if (symbol == '\\'){
                this->textdisplay->setStairs(i,j);
            }
            else if (symbol == '@'){
                this->player->setPos(i,j);
                this->textdisplay->setCharacter(i,j,'@');
            }
            else {
                continue;
            }
        }
    }
}

void Floor::init(){
    this->textdisplay = std::make_unique<Textdisplay>(25,81);
}

void Floor::pause(){
    for(unsigned int i = 0; i < this->enemies.size(); ++i){
        this->enemies[i]->setPause();
    }
}

void Floor::print(){
    this->textdisplay->print();
    std::cout << "Race: " << this->player->getRaceType() << "  Gold: " << this->player->getGold() << std::setw(57) << "Floor " << this->floorNum << std::endl;
    std::cout << "HP: " << this->player->getHealth() << std::endl;
    std::cout << "Atk: " << this->player->getAttack() + this->player->attackBuff() << std::endl;
    std::cout << "Def: " << this->player->getDefense() + this->player->defenseBuff() << std::endl;
    std::cout << "Action: " << this->action << std::endl; 
    this->action = "";
}

void Floor::setChambers(){
    for(int i = 0;i < 5; ++i){
        this->chambers.emplace_back(std::make_shared<Chamber>(i+1));
    }
}

void Floor::randomPlayer(){
    int size = this->chambers.size();
    int randomChamber = rand() % size;
    std::vector<int> Pos;
    Pos = this->chambers[randomChamber]->generateChamberPos();
    this->player->setPos(Pos[0],Pos[1]);
    this->textdisplay->setCharacter(Pos[0],Pos[1], '@');
}

void Floor::setEnemies(){
     for(int i = 0; i< 20; ++i){
        std::vector<int> Pos = this->generateValidPos();
        int randomEnemy = rand() % 19;
        if(randomEnemy >= 0 && randomEnemy <= 3){
            this->enemies.emplace_back(std::make_shared<Human>(Pos[0],Pos[1]));
            this->textdisplay->setCharacter(Pos[0],Pos[1],'H');
        } else if(randomEnemy >= 4 && randomEnemy <= 6){
            int randGold = rand() % 2 + 1;
            this->enemies.emplace_back(std::make_shared<Dwarf>(Pos[0],Pos[1],randGold));
            this->textdisplay->setCharacter(Pos[0],Pos[1],'W');
        }
        else if(randomEnemy >= 7 && randomEnemy <= 8){
            int randGold = rand() % 2 + 1;
            this->enemies.emplace_back(std::make_shared<Elf>(Pos[0],Pos[1],randGold));
            this->textdisplay->setCharacter(Pos[0],Pos[1],'E');
        }
        else if(randomEnemy >= 9 && randomEnemy <= 10){
            int randGold = rand() % 2 + 1;
            this->enemies.emplace_back(std::make_shared<Orcs>(Pos[0],Pos[1],randGold));
            this->textdisplay->setCharacter(Pos[0],Pos[1],'O');
        }
        else if(randomEnemy >= 11 && randomEnemy <= 12){
            this->enemies.emplace_back(std::make_shared<Merchant>(Pos[0],Pos[1]));
            this->textdisplay->setCharacter(Pos[0],Pos[1],'M');
        }
        else if(randomEnemy == 13) {
            this->enemies.emplace_back(std::make_shared<Superman>(Pos[0],Pos[1]));
            this->textdisplay->setCharacter(Pos[0],Pos[1],'S');
        }
        else {
            int randGold = rand() % 2 + 1;
            this->enemies.emplace_back(std::make_shared<Halfling>(Pos[0],Pos[1],randGold));
            this->textdisplay->setCharacter(Pos[0],Pos[1],'L');
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
            this->textdisplay->setCharacter(Pos[0],Pos[1],'G');
        } else if(randomGold >= 5 && randomGold <= 6){
            this->treasures.emplace_back(std::make_shared<Small>(Pos[0],Pos[1], this->player));
            this->textdisplay->setCharacter(Pos[0],Pos[1],'G');
        }
        else {
            auto dragonhoard = std::make_shared<DragonHoard>(Pos[0],Pos[1], this->player);
            this->treasures.emplace_back(dragonhoard);
            this->textdisplay->setCharacter(Pos[0],Pos[1],'G');
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
            this->textdisplay->setCharacter(Pos[0],Pos[1],'P');
        } else if(randomPotion == 1){
            this->potions.emplace_back(std::make_shared<PH>(Pos[0],Pos[1],this->player->getBuff()));
            this->textdisplay->setCharacter(Pos[0],Pos[1],'P');
        }
        else if(randomPotion == 2){
            this->potions.emplace_back(std::make_shared<BA>(Pos[0],Pos[1],this->player->getBuff()));
            this->textdisplay->setCharacter(Pos[0],Pos[1],'P');
        }
        else if(randomPotion == 3){
            this->potions.emplace_back(std::make_shared<WA>(Pos[0],Pos[1],this->player->getBuff()));
            this->textdisplay->setCharacter(Pos[0],Pos[1],'P');
        }
        else if(randomPotion == 4){
            this->potions.emplace_back(std::make_shared<BD>(Pos[0],Pos[1],this->player->getBuff()));
            this->textdisplay->setCharacter(Pos[0],Pos[1],'P');
        }
        else if(randomPotion == 5){
            this->potions.emplace_back(std::make_shared<WD>(Pos[0],Pos[1],this->player->getBuff()));
            this->textdisplay->setCharacter(Pos[0],Pos[1],'P');
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
    }
    else if(direction == "so"){
        nextRow += 1;
    }
    else if(direction == "ea"){
        nextCol += 1;
    }
    else if(direction == "we"){
        nextCol -= 1;
    }
    else if(direction == "ne"){
        nextRow -= 1;
        nextCol += 1;
    }
    else if(direction == "se"){
        nextRow += 1;
        nextCol += 1;
    }
    else if(direction == "sw"){
        nextRow += 1;
        nextCol -= 1;
    }
    else if(direction == "nw"){
        nextRow -= 1;
        nextCol -= 1;  
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

std::string directionInfull(std::string direction){
    if(direction == "no"){ return "North"; }
    else if(direction == "so"){ return "South"; }
    else if(direction == "ea"){ return "East"; }
    else if(direction == "we"){ return "West";}
    else if(direction == "ne"){ return "North East"; }
    else if(direction == "se"){ return "South East"; }
    else if(direction == "sw"){ return "South West"; }
    else { return "North West"; } 
}

void Floor::movePlayer(std::string direction, std::string command) {
    bool valid = false;
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
    if(valid){
        this->player->setPos(nextRow,nextCol);
        this->action = this->action + "Pc moves " + directionInfull(direction) + ". ";
        this->player->everyTurn();
        this->textdisplay->setSymbol(curRow, curCol);
        this->textdisplay->updateSymbol(nextRow, nextCol);
        this->textdisplay->setCharacter(nextRow,nextCol,'@');
    }
}

void Floor::attackPlayerOrMoveEnemies(){
    for (unsigned int i = 0; i < this->enemies.size(); i++){
        if (enemies[i]->checkPlayer(this->player->getRow(), this->player->getCol()) && enemies[i]->isHostile()){
            // if player is within the attack region of Enemy, then enemy attack player
            int healthBefore = this->player->getHealth();
            this->player->beAttacked(enemies[i]);
            int damage = healthBefore - this->player->getHealth();
            this->action = this->action + " " +this->enemies[i]->getRaceType() + " deals " + std::to_string(damage) + " to PC.";
            if(!this->player->isAlive()){
                throw DieException();
            }
        } else {
            // Player is not within range, Enemy move
            bool enemyMovable = false;
            for(int j = 0; j < 8; j++){
                std::vector<int> Pos = getPos(this->enemies[i]->getRow(), this->enemies[i]->getCol(), "nothing", j);
                if(this->textdisplay->checkEmpty(Pos[0], Pos[1])){
                    enemyMovable = true;
                    break;
                }
            }
            while(enemyMovable && enemies[i]->isMovable() && enemies[i]->isfMovable()){
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
    auto it = std::find_if(this->enemies.begin(), this->enemies.end(), [&row, &col](std::shared_ptr<Enemy>& enemies) { return (enemies->getRow() == row)&&(enemies->getCol() == col); });
    if(it != this->enemies.end()){
        int Healthbefore = (*it)->getHealth();
        (*it)->beAttacked(this->player);
        int damage = Healthbefore - (*it)->getHealth();
        if((*it)->isAlive()){ 
            this->action = "Pc deals " + std::to_string(damage) + " to " + (*it)->getRaceType() + ".";
            std::ifstream battle{"fight.txt"};
            std::cout << battle.rdbuf() << std::endl;
            usleep(800000);
        }
        // if Merchant being attacked, set all to hostile
        if(!(*it)->isHostile()) { 
            for(unsigned int i = 0; i < this->enemies.size(); ++i){
                enemies[i]->setHostile();
            } 
        }
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
            std::ifstream ko{"KO.txt"};
            std::cout << ko.rdbuf() << std::endl;
            usleep(800000);
            this->action = (*it)->getRaceType() + " has been slained";
            this->enemies.erase(it);
        }
    } else {
        throw AttackException();
    }
}

void Floor::pickPotion(int row, int col){
    auto it = std::find_if(this->potions.begin(), this->potions.end(), [&row, &col](std::shared_ptr<Potion>& potion) { return (potion->getRow() == row)&&(potion->getCol() == col); });
    (*it)->addBuff();
    this->action = "PC uses " + (*it)->getItemType();
    // add health if its health potion
    this->player->gainHp();
    this->potions.erase(it);
}

void Floor::pickGold(std::string direction){
    int curRow = this->player->getRow();
    int curCol = this->player->getCol();
    std::vector<int> newPos = getPos(curRow, curCol, direction, -1);
    int row = newPos[0];
    int col = newPos[1];
    auto it = std::find_if(this->treasures.begin(), this->treasures.end(), [&row, &col](std::shared_ptr<Treasure>& treasure) { return (treasure->getRow() == row)&&(treasure->getCol() == col); });
    if((*it)->isPickable()){
        (*it)->addGold();
        this->action = "PC picks " + (*it)->getItemType() + " and ";
        this->treasures.erase(it);
    } else {
        throw PickException();
    }
}

bool Floor::isTradable(int row, int col) {
    auto merchant = std::find_if(this->enemies.begin(), this->enemies.end(), [&row, &col](std::shared_ptr<Enemy>& enemies) { return (enemies->getRow() == row)&&(enemies->getCol() == col); });
    if(merchant != this->enemies.end() && !(*merchant)->isHostile()){
        return true;
    } else {
        return false;
    }
}

void Floor::addPotion(std::string pot) {
    if (pot == "RH") {
        auto potion = std::make_shared<RH>(-1,-1,this->player->getBuff());
        potion->addBuff();
        this->player->gainHp();
    } else if (pot == "BA") {
        auto potion = std::make_shared<BA>(-1,-1,this->player->getBuff());
        potion->addBuff();
    } else if (pot == "BD") {
        auto potion = std::make_shared<BD>(-1,-1,this->player->getBuff());
        potion->addBuff();
    } else if (pot == "PH") {
        auto potion = std::make_shared<PH>(-1,-1,this->player->getBuff());
        potion->addBuff();
        this->player->gainHp();
    } else if (pot == "WA") {
        auto potion = std::make_shared<WA>(-1,-1,this->player->getBuff());
        potion->addBuff();
    } else if (pot == "WD") {
        auto potion = std::make_shared<WD>(-1,-1,this->player->getBuff());
        potion->addBuff();
    }
}

