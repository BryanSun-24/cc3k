#ifndef ITEM_H
#define ITEM_H

#include "state.h"

class Item: public State {
    protected:
    int num;
    public:
    Item(int x, int y ,int num);
    virtual ~Item() {};
};

#endif

