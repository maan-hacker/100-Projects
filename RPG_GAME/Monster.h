#ifndef MONSTER_H
#define MONSTER_H

#include <iostream>
#include <string>
using namespace std;

class Monster {
	private:
		string type;
		int health, maxHealth;
		int attack;
		
	public:
		
		void generateMonster ();         // Member Function to generate Monster
		void showMonster();              // Member Function to spawn monster
		int getAttack();                 // Monster Attack Damage
		void takeDamage(int dmg);        // Member Function to cause damage that monster takes
		bool isAlive();                  // To know if the monster is alive?
		int getHealth();                 // To display health
		int getMaxHealth();              // To display max Health
		
};

#endif
