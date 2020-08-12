#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H

#include <vector>

class Floor;

class Textdisplay {
    std::vector<std::vector<char> > theDisplay;
    public:
    void print();
    void notify(Floor& floor);
};

#endif
