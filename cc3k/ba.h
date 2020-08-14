#ifndef BA_H
#define BA_H

#include "potion.h"

class BA: public Potion {
    public:
    BA(int x, int y, std::shared_ptr<Buff> buff);
    void addBuff() override;
};

#endif