#ifndef ITEM_H
#define ITEM_H

#include <string>
#include "state.h"

class Item: public State {
    std::string type;
    protected:
    int num;
    public:
    Item(int x, int y, std::string type ,int num);
    virtual ~Item() {};
    std::string getItemType();
};

#endif

