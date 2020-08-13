#ifndef RH_H
#define RH_H

#include "potion.h"
#include <memory>

class RH: public Potion {
    public:
    RH(int x, int y, std::shared_ptr<Buff> buff);
    void addBuff() override;
};

#endif
