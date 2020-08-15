#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H

#include <vector>
#include <iostream>


#define BOLDBLUE "\033[1m\033[34m"
#define BOLDYELLOW "\033[1m\033[33m"
#define BOLDGREEN "\033[1m\033[32m"
#define BOLDWHITE "\033[1m\033[37m"
#define BOLDMAGENTA "\033[1m\033[35m"
#define BOLDCYAN "\033[1m\033[36m"
#define BOLDRED "\033[1m\033[31m"
#define BOLDBLACK "\033[1m\033[30m"
#define REST "\033[0m"

class Floor;

class Textdisplay {
    std::vector<std::vector<char> > theDisplay;
    char prevSymbol;
    public:
    Textdisplay(int row, int col);
    void print();
    void notify(Floor& floor);
    void setCharacter(int row, int col, char symbol);
    void setSymbol(int row, int col);
    void setStairs(int row, int col);
    void setPotion(int row,int col);
    void setGold(int row, int col);
    void setHuman(int row, int col);
    void setDwarf(int row, int col);
    void setElf(int row, int col);
    void setOrcs(int row, int col);
    void setMerchant(int row, int col);
    void setHalfling(int row, int col);

    bool validMove(int row, int col);
    bool validMovePotion(int row, int col);
    
    void updateSymbol(int row, int col);
    bool checkStair(int nextRow,int nextCol);
    bool checkEmpty(int row, int col);
    char getSymbol(int row, int col);

    friend std::ostream &operator<<(std::ostream &out, const Textdisplay &td);
};

std::ostream &operator<<(std::ostream &out, const Textdisplay &td);

#endif
