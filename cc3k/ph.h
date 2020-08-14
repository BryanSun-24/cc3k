#ifndef PH_H
#define PH_H

#include "potion.h"

class PH: public Potion {
    public:
    PH(int x, int y, std::shared_ptr<Buff> buff);
    void addBuff() override;
};

#endif
