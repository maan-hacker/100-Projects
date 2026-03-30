#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

class Player : public Entity {
private:
    int level;

public:
    Player(string n, int h, int lvl) : Entity(n, h) {
        level = lvl;
    }

    void attack() override {
        cout << name << " (Player) attacks with skill!" << endl;
    }

    void showLevel() {
        cout << "Level: " << level << endl;
    }
};

#endif
