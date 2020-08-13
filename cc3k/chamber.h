#ifndef CHAMBER_H
#define CHAMBER_H

#include <vector>
#include "textdisplay.h"

class Chamber {
    int ID;
    std::vector<std::vector<int>> listofChamber;
    public:
    Chamber(int ID);
    std::vector<int> generateChamberPos();
    bool isValid();
    

};

#endif
