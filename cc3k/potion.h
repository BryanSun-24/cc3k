#ifndef POTION_H
#define POTION_H

#include "item.h"
#include <memory>

class Buff;

class Potion: public Item{
    protected:
    std::shared_ptr<Buff> buff;
    public:
    virtual int getEffect();
    virtual void addBuff();
};

#endif
