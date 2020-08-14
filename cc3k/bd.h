#ifndef BD_H
#define BD_H

#include "potion.h"

class BD: public Potion {
    public:
    BD(int x, int y, std::shared_ptr<Buff> buff);
    void addBuff() override;
};

#endif
