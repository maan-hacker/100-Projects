#include <iostream>
#include <fstream>
#include <cstdlib>
#include <windows.h>
using namespace std;


void writeData() {
	string name;
	int age;
	
	// Takes data and writes in file
		
		
		cin.ignore();
		cout << "Enter " << 1 << " Student Name: ";
		getline(cin, name);
	
		cout << "Enter " << 2 << " Student Age: ";
		cin >> age;
		cin.ignore();
		
		
		ofstream file("data.txt", ios::app); // Open File
		if (!file) {
			cout << "File failed to open.";
			return;
		}
		
		file << name << " ";
		file << age << endl;
		
		file.close();	
		cout << "\n\n\n";
}
	
void readData()	{

    // Reads data and prints in the console
	ifstream file("data.txt");   // Opens file
	string line;
			
	cout << "Data from File: \n\n";
	while (getline(file, line)) {      // Loop for reading data 
		cout << line << endl;	
	}		
	cout << "\n\n\n";

}


int main() {
	// Interface for writing and reading student data
	
	int choice = 0 ;
	while (choice != 3) {

		cout << "1. Write Student Data\n";
		cout << "2. Read Student Data\n";
		cout << "3. Exit.\n";
		cout << "Enter Choice: ";
		cin >> choice;
		
		switch (choice) {
			case 1:
				system("cls");
				writeData() ;
				break;
			case 2:
				system("cls");
				readData();
				break;
			case 3:
				cout << "Exiting...";
				Sleep(1000);
				cout << "Exited";
				break;
			default:
				cout << "You entered incorrect choice.";
		}
		
		
	}
	
	return 0;
}
