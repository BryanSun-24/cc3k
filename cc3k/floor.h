#ifndef FLOOR_H
#define FLOOR_H


#include <memory>
#include <vector>
#include "player.h"
#include "enemy.h"
#include "textdisplay.h"
#include "item.h"
#include "chamber.h"

class Floor {
    std::shared_ptr<Player> player;
    std::unique_ptr<Floor> floor;
    std::unique_ptr<Textdisplay> textdisplay;
    int floorNum;
    std::vector<Enemy> enemies;
    std::vector<Item> items;
    std::vector<std::shared_ptr<Chamber> > chambers;
    public:
    Floor(int num);
    void init();
    void print();
    void setChambers();
    void setEnemies();
    void setPlayer(std::shared_ptr<Player> player);
    void randomPlayer();
    void movePlayer(std::string direction);
    void setTreasure();
    void setPotion();
    void setDisplay();
};

#endif
