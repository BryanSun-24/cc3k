#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <vector>
#include <ctime>

#include "shade.h"
#include "vampire.h"
#include "drow.h"
#include "troll.h"

#include "floor.h"

#include "moveException.h"
#include "pickException.h"
#include "walkException.h"
#include "potionException.h"
#include "attackException.h"
#include "dieException.h"

int main(){
    srand((unsigned int)time(NULL));    
    // create 5 floors, push in to vector
    while(true){
        try{
            std::vector<std::shared_ptr<Floor>> floors;
            for (int i = 0; i < 5; ++i){ floors.emplace_back(std::make_shared<Floor>(i+1)); }

            // Choose your character
            char command;
            std::cout << "choose your hero, s for Shade" << std::endl;
            std::cout << "choose your hero, v for Vampire" << std::endl;
            std::cout << "choose your hero, t for Troll" << std::endl;
            std::cout << "choose your hero, d for Drow" << std::endl;
            std::cin >> command;
            std::shared_ptr<Player> player;
            auto buff = std::make_shared<Buff>();
            switch (command){
                case 's':
                    player = std::make_shared<Shade>(-1,-1, buff);
                case 'v':
                    player = std::make_shared<Vampire>(-1,-1, buff);
                case 't':
                    player = std::make_shared<Troll>(-1,-1, buff);
                case 'd':
                    player = std::make_shared<Drow>(-1,-1, buff);
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
                        catch(PotionException &e){
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
                        catch (AttackException &e) {
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
                            catch (PickException &e){
                                std::cout << "\033[1m\033[31m" << e.message() << REST << std::endl;
                            }
                        }else{
                            try{
                                floors[i]->movePlayer(direction,"normal");
                                floors[i]->attackPlayerOrMoveEnemies();
                                floors[i]->print();
                            }
                            catch (WalkException &e){
                                std::cout << "\033[1m\033[31m" << e.message() << REST << std::endl;
                            }
                            catch (MoveException &e){
                                std::cout << "\033[1m\033[31m" << e.message() << REST << std::endl;
                            }
                        }
                    }
                }
            }

            std::cout << "You win!!" << std::endl;
            std::cout << "Do you want to play again?" << std::endl;
            std::cout << "type y for Yes, n for No" << std::endl;
            while(true){
                std::cin >> command;
                if(command == 'y'){
                break;
                } else if(command == 'n'){
                    break;
                } else {
                    continue;
                }
            }
            if(command == 'y'){ continue; }
            if(command == 'n'){ break; }
        }
        catch(DieException &e){
            std::cout << "\033[1m\033[31m" << e.message() << REST << std::endl;
            std::cout << "Do you want to play again?" << std::endl;
            std::cout << "type y for Yes, n for No" << std::endl;
            char command;
            while(true){
                std::cin >> command;
                if(command == 'y'){
                break;
                } else if(command == 'n'){
                    break;
                } else {
                    continue;
                }
            }
            if(command == 'y'){ continue; }
            if(command == 'n'){ break; }
        }
    }
    return 0;
}
