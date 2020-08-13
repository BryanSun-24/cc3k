#ifndef STATE_H
#define STATE_H

class State {
    int x;
    int y;
    public:
    State(int x, int y);
    int getRow();
    int getCol();
    void setPos(int x, int y);
};

#endif
