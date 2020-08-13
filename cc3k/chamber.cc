#include "chamber.h"
#include <memory>
#include <cstdlib>

Chamber::Chamber(int ID): ID{ID}{
   for (int row = 0; row < 25; row++) {
        for (int col = 0; col < 79; col++) {
            std::vector<int> location;
            location.emplace_back(row);
            location.emplace_back(col);
            if(ID==1&&(3<=row<=6)&&(3<=col<=29)){
                listofChamber.emplace_back(location);
            }else if(ID==4&&(15<=row<=22)&&(4<=col<=24)){
                listofChamber.emplace_back(location);
            }else if(ID==3&&(10<=row<=12)&&(38<=col<=49)){
                listofChamber.emplace_back(location);
            }else if(ID==5&&(16<=row<=18)&&(65<=col<=75)){
                listofChamber.emplace_back(location);
            }else if(ID==5&&(19<=row<=21)&&(37<=col<=75)){
                listofChamber.emplace_back(location);
            }else if(ID==2&&(3<=row<=4)&&(39<=col<=61)){
                listofChamber.emplace_back(location);
            }else if(ID==2&&(row==5)&&(39<=col<=69)){
                listofChamber.emplace_back(location);
            }else if(ID==2&&(row==6)&&(39<=col<=72)){
                listofChamber.emplace_back(location);
            }else if(ID==2&&(3<=row<=4)&&(39<=col<=61)){
                listofChamber.emplace_back(location);
            }else if(ID==2&&(7<=row<=12)&&(61<=col<=75)){
                listofChamber.emplace_back(location);
            }
        }
   }
}

std::vector<int> Chamber::generateChamberPos(){
    int x;
    x = rand() % this->listofChamber.size();
    return listofChamber[x];
}

