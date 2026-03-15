#include <iostream>
using namespace std;

// This is a structure named by student.
struct Student{
	char name[20];
	int rollNo;
	int marks;
	
};

Student students[100];
int count = 0;

void addStudent(){
	cout << "Enter Name: ";
	cin.ignore();
	cin.getline(students[count].name, 20);
	cout << "Enter Roll Number: ";
	cin >> students[count].rollNo;
	cout << "Enter Marks: ";
	cin >> students[count].marks;
	
	
}
void displayStudent(){
	int rollNo;
	cout << "Enter roll number of the student: " ;
	cin >> rollNo;
	for(int i = 0; i<count; i++) {
		if (rollNo == students[i].rollNo){
			cout << "Name: " << students[i].name << endl;
			cout << "Roll Number: " << students[i].rollNo << endl;
			cout << "Marks: " << students[i].marks;
		}
	}
}




int main() {
	int choice = 0;
	
	do {
		cout << "\n----Student Management System----\n";
		cout << "1.Add";
		cout << "\n2.Display";
		cout << "\n3.Exit";
		cout << "\nEnter Choice: ";
		cin >> choice;
		
		switch (choice) {
			case 1:
				addStudent();
				count++;
				break;
			case 2:
				displayStudent();
				count++;
				break;
			case 3:
				choice = 0;
				break;
		}
	} while(choice != 0);
	
	return 0;
}




