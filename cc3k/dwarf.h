#ifndef DWARF_H
#define DWARF_H
#include <vector>
#include <memory>

#include "enemy.h"

class Dwarf: public Enemy {
    public:
    Dwarf(int x, int y, int gold);
};

#endif

