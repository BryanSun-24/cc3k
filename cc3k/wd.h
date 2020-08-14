#ifndef WD_H
#define WD_H

#include "potion.h"

class WD: public Potion {
    public:
    WD(int x, int y, std::shared_ptr<Buff> buff);
    void addBuff() override;
};

#endif
