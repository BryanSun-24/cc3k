#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <vector>
#include <ctime>

#include "shade.h"
#include "floor.h"

int main(){
    // 5个floor， 每一个floor都有一个textdisplay
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
                checkType = floors[i]->movePlayer(direction,"potion");
                floors[i]->pickPotion(player->getRow(), player->getCol());
                floors[i]->print();
                continue;
            }
            checkType = floors[i]->movePlayer(direction,"normal");
            std::cout << "checkType: " << checkType << std::endl;
            if(checkType == 'G'){
                floors[i]->pickGold(player->getRow(), player->getCol());
            }
            if(checkType=='\\'){ 
                player->resetBuff();
                break; 
            }
            // catch exception;
            // move enemy;
            floors[i]->print();
        }
        //floors[i]->print();
    }
    return 0;
}

