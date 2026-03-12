#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>
using namespace std;


class Player {       // Class of Player
	private:
		string name;
		int health;
		int level;
		int experience;
		int potions;
		string location;
		string weapon;
		int weaponDamage;
		int coins;
		
		
	public:
		int battlesWon;
		
		// Member Function to create a player
		void createPlayer() {
			cout << "Enter Your character name: ";
			cin >> name;
			
			health = 100;
			level = 1;
			experience = 0;
			potions = 2;
			
			coins = 50;
			weapon = "Rusty Sword";
			weaponDamage = 5;
			

			
			battlesWon = 0;
			location = "Village";
			
		}
		
		
		// Member Function to show stats of a player
		void showStats() {
			cout << "\n---- PLAYER STATS ----\n";
			cout << "Name: " << name << endl;
			cout << "Health: " << health << endl;
			cout << "Level: " << level << endl;
			cout << "Experience: " << experience << endl;
			cout << "Potions: " << potions << endl;
			cout << "Weapon: " << weapon << endl;
			cout << "Location: " << location << endl;
			cout << "Coins: " << coins << endl;
		}
		
		
		// Player Attack damage
		int getAttack() {
			return 10 + (level * 5) + weaponDamage;
		}
		
		// Damage that reduces player's hp
		void takeDamage(int dmg) {
			health = health - dmg;
			
			if (health < 0) health = 0;
		}
		
		// To know if the player is alive
		bool isAlive() {
			return health > 0;
		}
		
		// To display the health
		int getHealth() 
		{
			return health;
		}
		
		// Member Function to gain Experience
		void gainExperience(int exp)
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
		void usePotion() 
		{
			if (potions > 0) 
			{
				potions--;
				health += 40;
				
				if (health > 100 + level*20)
					health = 100 + level*20;
					
				cout << "You used a potion. Health restored!\n";
			}
			else
			{
				cout << "No potions left!\n";
			}
		}
		
		// Member Function to add Potion
		void addPotion() 
		{
			potions++;
		}
		
		// To display Potions in fight
		int getPotion() {
			return potions;
		}
		
		// Member Function to decide the player travel
		void travel() 
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
		string getLocation()
		{
			return location;
		}
		
		// Member Function to find Weapon for the player 
		friend void findWeapon(Player &player);
		
		// Member Function for coins for the player
		void addCoins(int amount)
		{
			coins += amount;
		}
		
		// Member Functions checks if purchase is possible and then returns the boolean value
		bool spendCoins (int amount) 
		{
			if (coins >= amount)
			{
				coins -= amount;
				return true;
			}
			
			return false;
		}
		
	
};


class Monster {      // Class of Monster
	private: 
		string type;
		int health;
		int attack;
		
	public:
		
		// Member Function to generate monster
		void generateMonster() {
			int r = rand()  % 3;
			
			if (r == 0) {
				type = "Goblin";
				health = 40;
				attack = 8;
			} 
			else if (r == 1){
				type = "Orc";
				health = 60;
				attack = 12;
			}
			else {
				type = "Dragon";
				health = 100;
				attack = 20;
			}
		}
		
		// Member Function to spawn monster
		void showMonster() {
			
			cout << "\nA wild " << type << " appears!\n";
			cout << "Health: " << health << endl;
			cout << "Attack: " << attack << endl;
		}
		
		
		// Monster Attack damage
		int getAttack() 
		{
			return attack;
		}
		
		// Damage that reduces monster's hp
		void takeDamage(int dmg) 
		{
			health = health - dmg;
			
			if (health < 0) health = 0;
		}
		
		// To know if the monster is alive
		bool isAlive() 
		{
			return health > 0;
		}
		
		// To display the health
		int gethealth()  {
			return health;
		}
};

class Boss {         // Class of Boss
	private:
		int health;
		int attack;
		
	public:
		
		void spawnBoss() {
			health = 200;
			attack = 25;
			
			cout << "\nA BOSS APPEARS!\n";
			cout << "The Demon King emerges from the shadows!\n";
			cout << "Health: " << health << endl;
			cout << "Attack: " << attack << endl;
		}
		
		int getAttack() 
		{
			return attack;
		}
		
		void takeDamage(int dmg)
		{
			health -= dmg;
			if (health < 0) health = 0;
		}
		
		bool isAlive() 
		{
			return health > 0;
		}
		
		// To show health in fight
		int getHealth() 
		{
			return health;
		}
};


void battle (Player &player);
void bossBattle (Player &player);

// Function to Explore
void explore (Player &player)
{
	cout << "You explore the " ;
	cout << player.getLocation() << "...\n";
	Sleep(1000);
	
	if (player.getLocation() == "Village")
	{
		cout << "You rest safely in the village.\n";
		player.usePotion();
	}
	else if(player.getLocation() == "Forest")
	{
		if (rand() % 2 == 0)
			battle(player);
		else 
			cout << "You found nothing in the forest.\n";
	}
	else if(player.getLocation() == "Dungeon")
	{
		if (rand() % 2 == 0)
		{
			cout << "A dangerous monster appears!\n";
			battle(player);
		}
		else 
			cout << "The dungeon is quiet...\n";
	}
	
}


// Function for Weapon Discovery
void findWeapon(Player &player)
{
	int roll = rand() % 3;
	
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



// Function for the shop
void shop( Player &player)
{
	int choice;
	                                                // Shop Menu
	cout << "\n----- VILLAGE SHOP -----\n";
	cout << "1. Buy Armor (30 Coins)\n";
	cout << "2. Buy Ring (50 Coings)\n";
	cout << "3. Buy Potion (20 Coins)\n";
	cout << "4. Exit shop\n";
	cout << "\nEnter Choice: ";
	
	cin >> choice;
	
	if (choice == 1)
	{
		if (player.spendCoins(30)) 
		{
			cout << "You bought armor. Health increased!\n";
		}
		else 
			cout << "Not Enough coins.\n";
	}
	
	else if(choice == 2)
	{
		if (player.spendCoins(50))
		{
			cout << "You bought a magic ring. Attack increased!\n";
		}
		else 
			cout << "Not enough coins.\n";
	}
	
	else if (choice == 3)
	{
		if (player.spendCoins(20))
		{
			player.addPotion();
			cout << "Potion purchased.\n";
		}
		else 
			cout << "Not enough coins.\n";
	}
	
	
}


int main() {
	system("color 0A");  
	srand(time(0));
	
	Player player;      // Object of Class Player
	
	int choice;
	
	player.createPlayer();
	
	do {
		
		cout << "\n----- RPG GAME MENU =====\n";
		cout << "1. Show Player Stats\n";
		cout << "2. Travel\n";
		cout << "3. Explore\n";
		cout << "4. Shop\n";
		cout << "5. Exit\n";
		
		cout << "Enter choice: ";
		cin >> choice;
		
		switch(choice) {
			case 1:
				system("cls");
				player.showStats();
				system("pause");
				break;
				
			case 2:
			 	system("cls");
			 	player.travel();
			 	system("pause");
			 	system("cls");
			 	break;
				
			case 3:
				system("cls");
				explore(player);
				system("pause");
				break;
				
			case 4:
				system("cls");
				shop(player);
				system("pause");
				break;
				
		}
	} while (choice !=5);
	system("cls");
	cout << "Exiting game....\n";
	
	
}


// Function for battle between player and monster
void battle (Player &player) 
{
	system("cls");                                  // Clear screen
	
	Monster monster;                                // Created monster
	monster.generateMonster();
	monster.showMonster();
	
	cout << "\nBattle starts!\n";
	
	
	while (player.isAlive() && monster.isAlive())    // Fight Loop
	{
		
		cout << "\n------------------------";
		cout << "\nYour Health: " << player.getHealth();
		cout << "\nMonster Health: " << monster.gethealth();
		cout << "\nPotions: " << player.getPotion();
		cout << "\n------------------------";
		cout << "\n1. Attack\n";
		cout << "2. Use Potion\n";
		
		int choice;
		cin >> choice;
		
		if (choice == 1) 
		{
		
			int roll = rand() % 100;  // 0-99 random Number
			
			if (roll < 70)
			{
				int dmg = player.getAttack();
				monster.takeDamage(dmg);
				
				cout << "You strike the monster!\n";
				cout << "Damage dealt: " << dmg << endl;
			}
			else if (roll < 90)
			{
				int dmg = player.getAttack() * 2;
				monster.takeDamage(dmg);
				
				cout << "CRITICAL HIT!\n";
				cout << "You dealt massive dammage: " << dmg << endl;
			}
			else
			{
				cout << "You swing your weapon...\n";
				cout << "But you missed!\n";
			}
			
		}
		else if(choice == 2)
		{
			player.usePotion();
		}
		
		Sleep(1000);
		
		if (monster.isAlive()) 
		{
			int roll = rand() % 100;
			
			if (roll < 80) 
			{
				int dmg = monster.getAttack();
			player.takeDamage(dmg);
			
			cout << "Monster attack you!\n";
			cout << "You lost " << dmg << " health!\n";
			}
			else 
			{
				int dmg = monster.getAttack() * 2;
				player.takeDamage(dmg);
			
				cout << "MONSTER CRITICAL ATTACK!\n";
				cout << "You lost " << dmg << " health!\n";
			}
			
			Sleep(1000);
		}
	}
	
	
	
	// Victory Section
	if (player.isAlive()) 
	{
		cout << "Monster defeated!\n";
		
		int exp = rand() % 40 + 20;                         // Exp Dropper Code
		cout << "You gained " << exp << " experience!\n";
		player.gainExperience(exp);
		
		
		if (rand() % 3 == 0)                                // Potion Dropper Code
		{
			cout << "The monster dropped a potion!\n";
			player.addPotion();
		}
		
		if (rand() % 4 == 0)                                // Weapon Dropper Code
		{
			cout << "The monster dropped a weapon!\n";
			findWeapon(player);
		}
		
		int gold = rand() % 20 + 30;                        // Coin Dropper Code
		cout << "Monster dropped " << gold << " coins!\n";
		player.addCoins(gold);
		
		player.battlesWon++;
		
		if (player.battlesWon  == 3)
		{
			cout << "\nYou feel a dark presence approacing...\n";
			Sleep(1500);
			
			bossBattle(player);
			
			player.battlesWon = 0;
		}
	}
	
}



void bossBattle (Player &player)
{
	Boss boss;
	boss.spawnBoss();
	
	cout << "\nFinal Battle Begins!\n";
	
	while (player.isAlive() && boss.isAlive())
	{
		
		cout << "\n------------------------";
		cout << "\nYour Health: " << player.getHealth();
		cout << "\nMonster Health: " << boss.getHealth();
		cout << "\nPotions: " << player.getPotion();
		cout << "\n------------------------";
		cout << "\n1. Attack\n";
		cout << "2. Use Potion\n";
		cout << "Enter Choice: ";
		int choice;
		cin >> choice;
		
		if(choice == 1)
		{
			int roll = rand() % 100;  // 0-99 random Number
			
			if (roll < 70)
			{
				int dmg = player.getAttack();
				boss.takeDamage(dmg);
				
				cout << "You strike the monster!\n";
				cout << "Damage dealt: " << dmg << endl;
			}
			else if (roll < 90)
			{
				int dmg = player.getAttack() * 2;
				boss.takeDamage(dmg);
				
				cout << "CRITICAL HIT!\n";
				cout << "You dealt massive dammage: " << dmg << endl;
			}
			else
			{
				cout << "You swing your weapon...\n";
				cout << "But you missed!\n";
			}
		}
		else if (choice == 2)
		{
			player.usePotion();
		}
		
		Sleep(1000);
		
		if (boss.isAlive())
		{
			player.takeDamage(boss.getAttack());
			cout << "The boss unleashes a powerful attack!\n";
		}
		
		Sleep(1000);
		
	}
	
	if (player.isAlive())
		cout << "\nYOU DEFEATED THE BOSS!\n";
	else 
		cout << "\nThe boss has defeated you...\n";
}







