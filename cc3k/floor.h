#ifndef FLOOR_H
#define FLOOR_H


#include <memory>
#include <vector>
#include "player.h"
#include "enemy.h"
#include "textdisplay.h"
#include "potion.h"
#include "treasure.h"
#include "chamber.h"

class Floor {
    std::shared_ptr<Player> player;
    std::unique_ptr<Floor> floor;
    std::unique_ptr<Textdisplay> textdisplay;
    int floorNum;
    std::vector<std::shared_ptr<Enemy> > enemies;
    std::vector<std::shared_ptr<Potion> > potions;
    std::vector<std::shared_ptr<Treasure> > treasures;
    std::vector<std::shared_ptr<Chamber> > chambers;
    public:
    Floor(int num);
    void readMap(std::string map, int row);
    void init();
    void print();
    void setChambers();
    void setEnemies();
    void setPlayer(std::shared_ptr<Player> player);
    void randomPlayer();
    void movePlayer(std::string direction,std::string command);
    char getSymbol(std::string direction);
    void setTreasures();
    void setPotions();
    void setStairs();
    void pickPotion(int row, int col);
    void pickGold(std::string direction);
    std::vector<int> generateValidPos();
    void attackPlayerOrMoveEnemies();
    void attackEnemy(int row, int col);


    std::vector<int> getPos(int x, int y, std::string direction, int direc);
};

#endif
