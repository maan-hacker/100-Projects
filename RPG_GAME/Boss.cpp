#include "Boss.h"


	// Member Function to spawn Boss
	void Boss::spawnBoss() {
			health = 200;
			attack = 25;
			
			cout << "\nA BOSS APPEARS!\n";
			cout << "The Demon King emerges from the shadows!\n";
			cout << "Health: " << health << endl;
			cout << "Attack: " << attack << endl;
		}
		
		// Member Function to call Boss's Attack
		int Boss::getAttack() 
		{
			return attack;
		}
		
		// To define the damage that the boss takes
		void Boss::takeDamage(int dmg)
		{
			health -= dmg;
			if (health < 0) health = 0;
		}
		
		// To check if the Boss is Alive?
		bool Boss::isAlive() 
		{
			return health > 0;
		}
		
		// To show health in fight
		int Boss::getHealth() 
		{
			return health;
		}
