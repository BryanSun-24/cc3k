#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <vector>


#include "shade.h"
#include "floor.h"

int main(){
    // 5个floor， 每一个floor都有一个textdisplay

    // create 5 floors, push in to vector
    std::vector<std::shared_ptr<Floor>> floors;
    for (int i = 0; i < 5; ++i){ floors.emplace_back(std::make_shared<Floor>(i)); }


    // Choose your character
    char command;
    std::cout << "choose your hero, s for Shade" << std::endl;
    std::cin >> command;
    std::shared_ptr<Player> player;
    if(command == 's'){
        player = std::make_shared<Shade>(-1,-1);
    }


    for(int i = 0; i < 5; ++i){
        floors[i]->init();
        floors[i]->setPlayer(player);
    }

    
    return 0;
}

