#include "Monster.h"

// Member Function to generate monster
		void Monster::generateMonster() {
			int r = rand()  % 3;
			
			if (r == 0) {
				type = "Goblin";
				health = 40;
				maxHealth = health;
				attack = 8;
			} 
			else if (r == 1){
				type = "Orc";
				health = 60;
				maxHealth = health;
				attack = 12;
			}
			else {
				type = "Dragon";
				health = 100;
				maxHealth = health;
				attack = 20;
			}
		}
		
		

// Member Function to spawn monster
		void Monster::showMonster() 
		{
			
			cout << "\nA wild " << type << " appears!\n";
			cout << "Health: " << health << endl;
			cout << "Attack: " << attack << endl;
		}
		
// Monster Attack damage
		int Monster::getAttack() 
		{
			return attack;
		}
		
// Damage that reduces monster's hp
		void Monster::takeDamage(int dmg) 
		{
			health = health - dmg;
			
			if (health < 0) health = 0;
		}
		
// To know if the monster is alive
		bool Monster::isAlive() 
		{
			return health > 0;
		}
		
// To display the health
		int Monster::getHealth()  {
			return health;
		}
		
// To display max Health
		int Monster::getMaxHealth()  {
			return maxHealth;
		}
