#ifndef TROLL_H
#define TROLL_H
#include "player.h"


class Troll: public Player {
    public:
    Troll(int x, int y, std::shared_ptr<Buff> buff);
    void beAttacked(std::shared_ptr<Enemy>& enemy) override;
    virtual void attack(Human& human) override;
    virtual void attack(Dwarf& dwarf) override;
    virtual void attack(Elf& elf) override;
    virtual void attack(Orcs& orcs) override;
    virtual void attack(Merchant& merchant) override;
    virtual void attack(Halfling& halfling) override;
    virtual void attack(Dragon& dragon) override;
    void everyTurn() override;
};

#endif

