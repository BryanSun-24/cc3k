#ifndef FLOOR_H
#define FLOOR_H


#include <memory>
#include <vector>
#include "character.h"
#include "textdisplay.h"
#include "item.h"
#include "chamber.h"

class Floor {
    std::unique_ptr<Character> player;
    std::unique_ptr<Floor> floor;
    std::unique_ptr<Textdisplay> textdisplay;
    int floorNum;
    std::vector<Character> enemies;
    std::vector<Item> items;
    std::vector<Chamber> chambers;
    public:
    void setChamber();
    void setEnemies();
    void setPlayer();
    void setTreasure();
    void setPotion();
    void setDisplay();
};

#endif
