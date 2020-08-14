#ifndef WA_H
#define WA_H

#include "potion.h"

class WA: public Potion {
    public:
    WA(int x, int y, std::shared_ptr<Buff> buff);
    void addBuff() override;
};

#endif
