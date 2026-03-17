#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include "Player.cpp"
#include "Monster.cpp"
#include "Boss.cpp"
#include "RPG_System.cpp"
using namespace std;


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











