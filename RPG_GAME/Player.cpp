#include "Player.h"
#include <cstdlib>
#include <string>

// Member Function to create a player
		void Player::createPlayer() {
			cout << "Enter Your character name: ";
			cin >> name;
			
			level = 1;
			experience = 0;
			potions = 2;
			
			Coins = 50;
			weapon = "Rusty Sword";
			weaponDamage = 5;
			
			maxHealth = 80 + level * 20;
			health = maxHealth;
			
			battlesWon = 0;
			location = "Village";
			
		}
		
		// Member Function to show stats of a player
		void Player::showStats() {
			cout << "\n---- PLAYER STATS ----\n";
			cout << "Name: " << name << endl;
			cout << "Health: " << health << endl;
			cout << "Level: " << level << endl;
			cout << "Experience: " << experience << endl;
			cout << "Potions: " << potions << endl;
			cout << "Weapon: " << weapon << endl;
			cout << "Location: " << location << endl;
			cout << "Coins: " << Coins << endl;
		}
		
		
		// Player Attack damage
		int Player::getAttack() {
			return 10 + (level * 5) + weaponDamage;
		}
		
		
		// Damage that reduces player's hp
		void Player::takeDamage(int dmg) {
			health = health - dmg;
			
			if (health < 0) health = 0;
		}
		
		
		// To know if the player is alive
		bool Player::isAlive() {
			return health > 0;
		}
		
		// To display the health
		int Player::getHealth() 
		{
				return health;
		}
		
		
		// To display max health
		int Player::getMaxHealth() 
		{
			return maxHealth;
		}
		
		
		// Member Function to gain Experience
		void Player::gainExperience(int exp)
		{
			experience += exp;
			
			if(experience >= 100) 
			{
				level++;
				experience = 0;
				
				cout << "\n*** LEVEL UP! ***\n";
				cout << "You are now level " << level << endl;
				
				health = 100 + (level * 20);
				
					
			}
		}
		
		// Member function for the potion use of player
		void Player::usePotion() 
		{
			if (potions > 0) 
			{
				potions--;
				health += 40;
				if (health > maxHealth)
					health = maxHealth;
					
				cout << "You used a potion. Health restored!\n";
			}
			else
			{
				cout << "No potions left!\n";
			}
		}
		
		
		// Member Function to add Potion
		void Player::addPotion() 
		{
			potions++;
		}
		
		// To display Potions in fight
		int Player::getPotion() {
			return potions;
		}
		
		
		// Member Function to decide the player travel
		void Player::travel() 
		{
			int choice;
			
			cout << "\nWhere do you want to go?\n";
			cout << "1. Forest\n";
			cout << "2. Dungeon\n";
			cout << "3. Village\n";
			
			cin >> choice;
			
			if (choice == 1)
				location = "Forest";
			else if (choice == 2)
				location = "Dungeon";
			else 
				location = "Village";
				
			cout << "You travel to the " << location << ".\n";
		}
		
		
		// Member Function to display location
		string Player::getLocation()
		{
			return location;
		}
		
		// Function for Weapon Discovery
		void findWeapon(Player &player)
		{
			int	roll = rand() % 3;
	
			if (roll == 0)
			{
				cout << "You found an Iron Sword!\n";
				player.weapon = "Iron Sword";
				player.weaponDamage = 10;
			}
			else if (roll == 1)
			{
				cout << "You found a Steel Blade!\n";
				player.weapon = "Steel Blade";
				player.weaponDamage = 15;
			}
			else 
			{
				cout << "You found a Legendary Sword!\n";
				player.weapon = "legendary Sword";
				player.weaponDamage = 25;
			}
		}
		
		// Member Function for coins for the player
		void Player::addCoins(int amount)
		{
			Coins += amount;
		}
		
		// Member Functions checks if purchase is possible and then returns the boolean value
		bool Player::spendCoins(int amount) 
		{
			if (Coins >= amount)
			{
				Coins -= amount;
				return true;
			}
			
			return false;
		}
		
