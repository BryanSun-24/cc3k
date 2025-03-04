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
#include "goblin.h"
#include "batman.h"

#include "floor.h"
 
#include "moveException.h"
#include "pickException.h"
#include "walkException.h"
#include "potionException.h"
#include "attackException.h"
#include "dieException.h"
#include "quitException.h"
#include "restartException.h"
#include "storeException.h"
#include "buyException.h"
#include "goldException.h"

int main(int argc, char * argv[]){
    srand((unsigned int)time(NULL));    
    // create 5 floors, push in to vector
    while(true){
        try{
            std::ifstream welcome{"welcome.txt"};
            std::cout << welcome.rdbuf() << std::endl;
            std::vector<std::shared_ptr<Floor>> floors;

            for (int i = 0; i < 5; ++i){ floors.emplace_back(std::make_shared<Floor>(i+1)); }

            // Choose your character
            char command;
            std::cout << "Choose Your Hero!" << std::endl;
            std::cout << "\033[1m\033[31m" << "s" << REST << " for Shade"<< std::endl;
            std::cout << "\033[1m\033[31m" << "v" << REST << " for Vampire, " << "gains 5 HP every successful attack and has no maximum HP" << std::endl;
            std::cout << "\033[1m\033[31m" << "t" << REST << " for Troll, " << "regains 5 HP every turn; HP is capped at 120 HP" << std::endl;
            std::cout << "\033[1m\033[31m" << "d" << REST << " for Drow, " << "all potions have their effect magnified by 1.5" << std::endl;
            std::cout << "\033[1m\033[31m" << "g" << REST << " for Goblin, " << "steals 5 gold from every slain enemy" << std::endl;
            std::cout << "\033[1m\033[31m" << "b" << REST << " for Batman, " << "rich, have 50 gold when spawned" << std::endl;
            std::cin >> command;
            std::shared_ptr<Player> player;
            auto buff = std::make_shared<Buff>();
            switch (command){
                case 's':
                    player = std::make_shared<Shade>(-1,-1, buff);
                    break;
                case 'v':
                    player = std::make_shared<Vampire>(-1,-1, buff);
                    break;
                case 't':
                    player = std::make_shared<Troll>(-1,-1, buff);
                    break;
                case 'd':
                    player = std::make_shared<Drow>(-1,-1, buff);
                    break;
                case 'g':
                    player = std::make_shared<Goblin>(-1,-1, buff);
                    break;
                case 'b':
                    player = std::make_shared<Batman>(-1,-1, buff);
                    break;
                default:
                    player = std::make_shared<Shade>(-1,-1, buff);
                    break;
            }

            for(int i = 0; i < 5; ++i){
                std::string direction;
                char checkType;
                floors[i]->init();
                floors[i]->setPlayer(player);
                if(argc > 1){
                    floors[i]->readMap(argv[1],i * 25);
                } else{
                    floors[i]->setChambers();
                    floors[i]->randomPlayer();
                    floors[i]->setStairs();
                    floors[i]->setPotions();
                    floors[i]->setTreasures();
                    floors[i]->setEnemies();
                }
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
                        catch (MoveException &e){
                            std::cout << "\033[1m\033[31m" << e.message() << REST << std::endl;
                            continue;
                        }
                        catch (AttackException &e) {
                            std::cout << "\033[1m\033[31m" << e.message() << REST << std::endl;
                            continue;
                        }
                    } else if(direction == "f"){
                        floors[i]->pause();
                    } else if(direction == "q"){
                        throw QuitException();
                    } else if(direction == "r"){
                        throw RestartException();


                    } else if(direction == "b"){
                        std::cin >> direction;
                        try{
                            std::vector<int> Pos = floors[i]->getPos(player->getRow(),player->getCol(), direction, -1);
                            char check = floors[i]->getSymbol(direction);
                            if(check == 'M'){
                                if (floors[i]->isTradable(Pos[0],Pos[1])){
                                    std::ifstream store{"potion.txt"};
                                    std::cout << store.rdbuf() << std::endl;
                                    std::cin >> direction;
                                    if(player->getGold() < 5) { floors[i]->print(); throw GoldException(); }
                                    if (direction == "1"){
                                        player->addGold(-5);
                                        floors[i]->addPotion("RH");
                                        floors[i]->print();
                                        continue;
                                    } else if (direction == "2"){
                                        player->addGold(-5);
                                        floors[i]->addPotion("BA");
                                        floors[i]->print();
                                        continue;
                                    } else if (direction == "3"){
                                        player->addGold(-5);
                                        floors[i]->addPotion("BD");
                                        floors[i]->print();
                                        continue;
                                    } else if (direction == "4"){
                                        player->addGold(-5);
                                        floors[i]->addPotion("PH");
                                        floors[i]->print();
                                        continue;
                                    } else if (direction == "5"){
                                        player->addGold(-5);
                                        floors[i]->addPotion("WA");
                                        floors[i]->print();
                                        continue;
                                    } else if (direction == "6"){
                                        player->addGold(-5);
                                        floors[i]->addPotion("WD");
                                        floors[i]->print();
                                        continue;
                                    } else {
                                        throw MoveException();
                                        continue;
                                    }
                                } else {
                                    throw StoreException();
                                }
                            } else {
                                throw BuyException();
                            }
                        }
                        catch (Exception &e){
                            std::cout << "\033[1m\033[31m" << e.message() << REST << std::endl;
                            continue;
                        }
                    } 
                    else {
                        try{
                            checkType = floors[i]->getSymbol(direction);
                        }
                        catch(MoveException &e){
                            std::cout << "\033[1m\033[31m" << e.message() << REST << std::endl;
                            continue;
                        }
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
            std::ifstream win{"winning.txt"};
            std::cout << win.rdbuf() << std::endl;
            std::cout << "\033[1m\033[35m" << "Do you want to play again?" << REST << std::endl;
            std::cout <<"type " << "\033[1m\033[31m" << "y" << REST << " for Yes," << "\033[1m\033[31m" << " n " << REST << "for No" << REST << std::endl;
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
            std::ifstream lose{"lose.txt"};
            std::cout << lose.rdbuf() << std::endl;
            std::cout << "\033[1m\033[35m" << "Do you want to play again?" << REST << std::endl;
            std::cout <<"type " << "\033[1m\033[31m" << "y" << REST << " for Yes," << "\033[1m\033[31m" << " n " << REST << "for No" << REST << std::endl;
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
        catch(QuitException &e){
            break;
        }
        catch(RestartException &e){
            continue;
        }
    }
    std::ifstream bye{"byebye.txt"};
    std::cout << bye.rdbuf() << std::endl;
    return 0;
}
