#ifndef DRAGON_H
#define DRAGON_H

#include <memory>
#include "enemy.h"
#include "dragonhoard.h"

class Dragon: public Enemy {
    bool isKilled;
    std::shared_ptr<DragonHoard> dragonHoard;
};

#endif

