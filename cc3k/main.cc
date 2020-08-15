#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <vector>
#include <ctime>

#include "shade.h"
#include "floor.h"

#include "Exception.h"

int main(){
    srand((unsigned int)time(NULL));    
    // create 5 floors, push in to vector
    std::vector<std::shared_ptr<Floor>> floors;
    for (int i = 0; i < 5; ++i){ floors.emplace_back(std::make_shared<Floor>(i+1)); }


    // Choose your character
    char command;
    std::cout << "choose your hero, s for Shade" << std::endl;
    std::cin >> command;
    std::shared_ptr<Player> player;
    auto buff = std::make_shared<Buff>();
    if(command == 's'){
        player = std::make_shared<Shade>(-1,-1, buff);
    }

    for(int i = 0; i < 5; ++i){
        std::string direction;
        char checkType;
        floors[i]->init();
        floors[i]->setPlayer(player);
        floors[i]->setChambers();
        floors[i]->randomPlayer();
        floors[i]->setStairs();
        floors[i]->setPotions();
        floors[i]->setTreasures();
        floors[i]->setEnemies();
        floors[i]->print();
        while(std::cin >> direction){
            if(direction == "u"){
                std::cin >> direction;
                try{
                    floors[i]->movePlayer(direction,"potion");
                    floors[i]->pickPotion(player->getRow(), player->getCol());
                    floors[i]->print();
                    continue;
                }
                catch(Exception &e){
                    std::cout << "\033[1m\033[31m" << e.message() << REST << std::endl;
                    continue;
                }
            } else if(direction == "a"){
                std::cin >> direction;
                try{
                    std::vector<int> Pos = floors[i]->getPos(player->getRow(),player->getCol(), direction, -1);
                    floors[i]->attackEnemy(Pos[0], Pos[1]);
                    floors[i]->attackPlayerOrMoveEnemies();
                    floors[i]->print();
                    continue;
                }
                catch (Exception &e) {
                    std::cout << "\033[1m\033[31m" << e.message() << REST << std::endl;
                    continue;
                }
            } else {
                checkType = floors[i]->getSymbol(direction);
                if(checkType=='\\'){ 
                    player->resetBuff();
                    break; 
                }
                if(checkType == 'G'){  
                    try{
                        floors[i]->pickGold(direction);
                        floors[i]->movePlayer(direction,"normal");
                        floors[i]->attackPlayerOrMoveEnemies();
                        floors[i]->print();
                    }
                    catch (Exception &e){
                        std::cout << "\033[1m\033[31m" << e.message() << REST << std::endl;
                    }
                }else{
                    try{
                        floors[i]->movePlayer(direction,"normal");
                        floors[i]->attackPlayerOrMoveEnemies();
                        floors[i]->print();
                    }
                    catch (Exception &e){
                        std::cout << "\033[1m\033[31m" << e.message() << REST << std::endl;
                    }
                }
            }
        }
    }
    std::cout << "You win!!" << std::endl;
    return 0;
}
