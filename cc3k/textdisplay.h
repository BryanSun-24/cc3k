#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H

#include <vector>
#include <iostream>

class Floor;

class Textdisplay {
    std::vector<std::vector<char> > theDisplay;
    public:
    Textdisplay(int row, int col);
    void print();
    void notify(Floor& floor);
    void setPlayer(int row, int col);
    void setEmpty(int row, int col);
    bool validMove(int row, int col);

    friend std::ostream &operator<<(std::ostream &out, const Textdisplay &td);
};

std::ostream &operator<<(std::ostream &out, const Textdisplay &td);

#endif
