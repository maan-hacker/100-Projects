#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
using namespace std;


class Player {
	
	private:
		string name;
		int health, maxHealth;
		int level;
		int experience;
		int potions;
		int Coins;
		string location;
		string weapon;
		int weaponDamage;
		
	public:
		int battlesWon;
		
		void createPlayer ();                                // Member Function to create a player
		void showStats ();                                   // Member Function to show stats of a player
		int getAttack ();                                    // Player Attack Damage
		void takeDamage (int dmg);                           // Damage that user takes
		bool isAlive ();                                     // To know if the player is alive
		int getHealth ();                                    // To display the health
		int getMaxHealth ();                                 // To display max health
		void gainExperience (int exp);                       // Member Function to gain Experience
		void usePotion ();                                   // Member Function for the potion to be used by the player
		void addPotion ();                                   // Member function to add Potions
		int getPotion ();                                    // To display Potions in battle
		void travel();                                       // Member Function to decided the player travel
		string getLocation ();                               // Member Function to display location
		friend void findWeapon (Player &player);             // Member Function to find weapon for the player
		void addCoins (int amount);                          // Member Function for coins for the player
		bool spendCoins (int amount);                        // Member Functions checks if purchase is possible and then returns the boolean value
		
};




#endif
