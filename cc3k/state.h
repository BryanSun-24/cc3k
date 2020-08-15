#ifndef STATE_H
#define STATE_H

class State {
    int x;
    int y;
    public:
    State(int x, int y);
    virtual ~State() {};
    int getRow();
    int getCol();
    virtual void setPos(int x, int y);
};

#endif
