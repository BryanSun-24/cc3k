#ifndef SHADE_H
#define SHADE_H
#include "player.h"

class Buff;

class Shade: public Player {
    public:
    Shade(int x, int y, std::shared_ptr<Buff> buff);
    virtual void attack(Human& human) override;
    virtual void attack(Dwarf& dwarf) override;
    virtual void attack(Elf& elf) override;
    virtual void attack(Orcs& orcs) override;
    virtual void attack(Merchant& merchant) override;
    virtual void attack(Halfling& halfling) override;
    virtual void attack(Dragon& dragon) override;
    virtual void beAttacked(std::shared_ptr<Enemy>& enemy) override;
    virtual void specialAbility() override;
};

#endif

