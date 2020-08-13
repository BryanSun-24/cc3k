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

    friend std::ostream &operator<<(std::ostream &out, const Textdisplay &td);
};

std::ostream &operator<<(std::ostream &out, const Textdisplay &td);

#endif
