#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"

class Enemy : public Entity {
private:
    int damage;

public:
    Enemy(string n, int h, int dmg) : Entity(n, h) {
        damage = dmg;
    }

    void attack() override {
        cout << name << " (Enemy) attacks with " << damage << " damage!" << endl;
    }

    int getDamage() {
        return damage;
    }
};

#endif
