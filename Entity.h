#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <string>
using namespace std;

class Entity {
protected:
    string name;
    int health;

public:
    // Constructor
    Entity(string n, int h) {
        name = n;
        health = h;
    }

    // Virtual destructor (important in OOP)
    virtual ~Entity() {}

    // Virtual functions (to be overridden)
    virtual void attack() {
        cout << name << " attacks!" << endl;
    }

    virtual void takeDamage(int damage) {
        health -= damage;
        cout << name << " takes " << damage << " damage. Health: " << health << endl;
    }

    void showStatus() {
        cout << "Name: " << name << " | Health: " << health << endl;
    }
};

#endif
