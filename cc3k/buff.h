#ifndef BUFF_H
#define BUFF_H


class Buff {
    int attack;
    int defense;
    int health;
    public:
    Buff();
    int getAttack();
    int getDefense();
    int getHealth();
    void attackPotion(int attack);
    void defensePotion(int defense);
    void healthPotion(int health);
    void reset();
};

#endif

