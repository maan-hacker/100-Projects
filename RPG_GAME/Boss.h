#ifndef BOSS_H
#define Boss_h

#include <iostream>
#include <string>
using namespace std;

class Boss {
	private:
		int health;
		int attack;
		
	public:
		
		void spawnBoss();                 // Member Function to spawn Boss
		int getAttack();                  // Member Function to call Boss's Attack
		void takeDamage(int dmg);         // To define the damage that the boss takes
		bool isAlive();                   // To check if the Boss is Alive?
		int getHealth();                  // to show Health in Battle
};

#endif
