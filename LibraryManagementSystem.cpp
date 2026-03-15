#include <iostream>
using namespace std;

struct Book {
	int id;
	string title;
	string author;
	float price;
	int quantity; 
};
 
  Book books[100];
 int totalBooks = 0;
 
 void addBook();
 void displayBooks();
 void searchBook();
 void deleteBook();
 void searchTitle();
void checkQuantity();


int main(){
	
	int choice;
	
	while(true) {
		cout << "\n=== Book Management System ===\n";
		cout << "1. Add Book \n";
		cout << "2. Display Books\n";
		cout << "3. Search Book \n";
		cout << "4. Search Book by Title \n";
		cout << "5. Delete Book\n";
		cout << "6. Find Quantity of a Book \n";
		cout << "7. Exit\n";
		cout << "Enter choice: ";
		cin >> choice;
	
	
	switch(choice) {
		case 1: 
			addBook(); 
			break;
		case 2:
			displayBooks();
			break;
		case 3:
			searchBook();
			break;
		case 4: 
			searchTitle();
			break;
		case 5: 
			deleteBook();
			break;
		case 6:
			checkQuantity();
			break;
		case 7: 
			return 0;
		default:
			cout << "Invalid choice.\n";
		}
	}
	
	return 0;
};

 void addBook() {
 	cout << "Enter Book ID: ";
 	cin >> books[totalBooks].id;
 	
 	cout << "Enter Title (single word): ";
 	cin >> books[totalBooks].title;
 	
 	cout << "Enter Author (single word): ";
 	cin >> books[totalBooks].author;
 	
 	cout << "Enter Price: ";
 	cin >> books[totalBooks].price;
 	
 	cout << "Enter Quantity: ";
 	cin >> books[totalBooks].quantity;
 	
 	totalBooks++;
 	cout << "Book Added!\n";
 }
 
 void displayBooks() {
 	if (totalBooks == 0) {
 		cout << "No books available.\n";
 		return;
	 }
	 
	 for(int i=0; i< totalBooks; i++) {
	 	cout << "\nBook #" << i + 1 << endl;
	 	cout << "ID: " << books[i].id << endl;
	 	cout << "Title: " << books[i].title << endl;
	 	cout << "Author: " << books[i].author << endl;
	 	cout << "Price: " << books[i].price << endl;
	 	cout << "Quantity: " << books[i].quantity << endl;
	 }
 }
 
 void searchBook() {
 	int id;
 	cout << "Enter Book ID to search: ";
 	cin >> id;
 	
 	for (int i=0; i < totalBooks; i++) {
 		if (books[i].id == id) {
 			cout << "Book Found:\n";
 			cout << "Title: " << books[i].title << endl;
 			cout << "Author: " << books[i].author << endl;
 			cout << "Price: " << books[i].price << endl;
 			cout << "Quantity: " << books[i].price << endl;
 			return;
		 }
	 }
	 
	 cout << "Book Not Found.\n";
 }
  
 void deleteBook() {
 	int id;
 	cout << "Enter book ID to delete: ";
 	cin >> id;
 	
 	for (int i = 0; i < totalBooks; i++){
 		if (books[i].id == id){
 			for (int j = i; j < totalBooks - 1; j++) {
 				books[j] = books[j + 1];
			 }
			 totalBooks--;
			 cout << "Book Deleted.\n";
			 return;
		 }
	 }
	 cout << "Book Not Fount.\n";
 }
 
 
 void searchTitle(){
 	char title[50]; 
 	int found = 0;
 	cout << "Enter Title of book to search: ";
 	cin.ignore();
 	cin.getline(title, 50);
 	for (int i = 0; i < totalBooks; i++) {
 		if (title == books[i].title){
 			
	 		cout << "ID: " << books[i].id << endl;
	 		cout << "Title: " << books[i].title << endl;
	 		cout << "Author: " << books[i].author << endl;
	 		cout << "Price: " << books[i].price << endl;
	 		cout << "Quantity: " << books[i].quantity << endl;
 			found++;
 			break;
 		}
	 }
	if (found ==0)
	 	cout << "\n\"Book Not Found!\"\n\n";
 }
 
 void checkQuantity() {
 	char title[50]; 
 	int found = 0;
 	cout << "Enter Title of book to find its quantity: ";
 	cin.ignore();
 	cin.getline(title, 50);
 	for (int i = 0; i < totalBooks; i++) {
 		if (title == books[i].title){
 			
	 		cout << "\nQuantity: " << books[i].quantity << endl;
 			found++;
 			break;
 		}
	 }
	if (found ==0)
	 	cout << "\n\"Book Not Found!\"\n\n";
 }
