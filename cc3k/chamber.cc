#include "chamber.h"
#include <memory>
#include <cstdlib>

Chamber::Chamber(int ID): ID{ID}{
   for (int row = 0; row < 25; row++) {
        for (int col = 0; col < 79; col++) {
            std::vector<int> location;
            location.emplace_back(row);
            location.emplace_back(col);
            if(ID==1&&(3<=row)&&(row<=6)&&(3<=col)&&(col<=28)){
                listofChamber.emplace_back(location);
            }else if(ID==4&&(15<=row)&&(row<=21)&&(4<=col)&&(col<=24)){
                listofChamber.emplace_back(location);
            }else if(ID==3&&(10<=row)&&(row<=12)&&(38<=col)&&(col<=49)){
                listofChamber.emplace_back(location);
            }else if(ID==5&&(16<=row)&&(row<=18)&&(65<=col)&&(col<=75)){
                listofChamber.emplace_back(location);
            }else if(ID==5&&(19<=row)&&(row<=21)&&(37<=col)&&(col<=75)){
                listofChamber.emplace_back(location);
            }else if(ID==2&&(3<=row)&&(row<=4)&&(39<=col)&&(col<=61)){
                listofChamber.emplace_back(location);
            }else if(ID==2&&(row==5)&&(39<=col)&&(col<=69)){
                listofChamber.emplace_back(location);
            }else if(ID==2&&(row==6)&&(39<=col)&&(col<=72)){
                listofChamber.emplace_back(location);
            }else if(ID==2&&(3<=row)&&(row<=4)&&(39<=col)&&(col<=61)){
                listofChamber.emplace_back(location);
            }else if(ID==2&&(7<=row)&&(row<=12)&&(61<=col)&&(col<=75)){
                listofChamber.emplace_back(location);
            }else {
                continue;
            }
        }
   }
}

std::vector<int> Chamber::generateChamberPos(){
    //std::cout << "called generateChamber" << std::endl;
    int x;
    int size = this->listofChamber.size();
    std::cout << "size: " << size << std::endl;
    x = rand() % size;
    //std::cout << "random x: "<< x << std::endl;
    return listofChamber[x];
}

