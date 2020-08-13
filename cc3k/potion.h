#ifndef POTION_H
#define POTION_H

#include "item.h"
#include <memory>
#include "buff.h"

class Potion: public Item{
    protected:
    std::shared_ptr<Buff> buff;
    public:
    Potion(int x, int y, int num, std::shared_ptr<Buff> buff);
    virtual int getEffect();
    virtual void addBuff() = 0;
};

#endif
