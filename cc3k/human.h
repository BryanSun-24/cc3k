#ifndef HUMAN_H
#define HUMAN_H
#include <vector>
#include <memory>

#include "enemy.h"
#include "normal.h"

class Human: public Enemy {
    std::vector< std::shared_ptr<Normal> > piles;
};

#endif

