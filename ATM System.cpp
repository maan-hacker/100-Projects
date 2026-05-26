#include <iostream>
using namespace std;

// Structure representing one bank account
struct Account {
	int accountNumber;       // Unique ID for each user
	string name;             // Account holder name
	int pin;                 // Security PIN
	double balance;          // Money in account
};

// Array to store multiple accounts (bank database in memory)
Account accounts[100];       // Can store up to 100 users

int totalAccounts = 0;       // Tracks how many accounts currently exist


// Function to create a new bank account
void createAccount() {
	// Check if bank storage is full
	if (totalAccounts >= 100) {
		cout << "Bank storage full. Cannot create more accounts.\n";
		return ;
	}
	
	Account newAcc;
	cout << "Enter your name: ";
	cin >> newAcc.name;
	
	cout << "Set a 4-digit PIN: ";
	cin >> newAcc.pin;
	
	cout << "Enter starting balance: ";
	cin >> newAcc.balance;
	
	// Automatically assign account number
	newAcc.accountNumber = 1000 + totalAccounts;
	
	// Store account in array
	accounts[totalAccounts] = newAcc;
	
	// Increase count of accounts
	totalAccounts++;
	
	cout << "Account created successfully!\n";
	cout << "Your Account Number is: " << newAcc.accountNumber << "\n";
}

// Function to login and return index of logged-in  account
int login() {
	int accNum, enteredPin;
	
	cout << "Enter Account Number: ";
	cin >> accNum;
	
	cout << "Enter PIN: ";
	cin >> enteredPin;
	
	// Search through all existing accounts
	for (int i=0; i< totalAccounts; i++){
		if (accounts[i].accountNumber == accNum && accounts[i].pin == enteredPin) {
			cout << "Login succesfull!\n";
			return i;                 // return index of account
		}
	}
	
	cout << "Invalid Account Number or PIN.\n";
	return -1;                        // login failed
}

// Function to display balance
void checkBalance(int userIndex) {
	cout << "Your current balance is: " << accounts[userIndex].balance << "\n";
}

// Function to deposit money
void depositMoney(int userIndex) {
	double amount;
	
	cout << "Enter amount to deposit: ";
	cin >> amount;
	
	// Check for invalid amount
	if (amount <=0) {
		cout << "Invalid amount. Deposit must be positive.\n";
		return;
	}
	
	accounts[userIndex].balance += amount;
	
	cout << "Deposit succesful.\n";
	cout << "New balance: " << accounts[userIndex].balance << "\n";
}

// Function to withdraw money 
void withdrawMoney (int userIndex) {
	double amount;
	
	cout << "Enter amount to withdraw: ";
	cin >> amount;
	
	// Check invalid input
	if (amount <= 0) {
		cout << "Invalid amount. \n";
		return ;
	} 
	
	// Check if enough balance exists
	if (amount > accounts[userIndex].balance) {
		cout << "Insufficient balance.\n";
		return ;
	}
	
	accounts[userIndex].balance -= amount;
	
	cout << "Withdraw successful.\n";
	cout << "Remaining balance:" << accounts[userIndex].balance << "\n";
}

// Function to transfer money
void transferMoney (int senderIndex) {
	int receiverAccNum;
	double amount;
	int receiverIndex = -1;
	
	cout << "Enter receiver account number: ";
	cin >> receiverAccNum;
	
	// Find receiver account
	for (int i=0; i < totalAccounts; i++) {
		if (accounts[i].accountNumber == receiverAccNum) {
			receiverIndex = i;
			break;
		}
	}
	
	// Check if receiver exists
	if (receiverIndex == -1) {
		cout << "Receiver account not found. \n";
		return;
	}
	
	cout << "Enter amount to transfer: ";
	cin >> amount;
	
	// Check sender balance
	if (amount > accounts[senderIndex].balance) {
		cout << "Insufficient balance.\n";
		return;
	}
	
	// Perform transfer
	accounts[senderIndex].balance -= amount;
	accounts[receiverIndex].balance += amount;
	
	cout << "Transfer successful.\n";
}

// Function to change PIN
void changePin(int userIndex) {
	int oldPin, newPin;
	
	cout << "Enter current PIN: ";
	cin >> oldPin;
	
	// Verify old PIN
	if (oldPin != accounts[userIndex].pin) {
		cout << "Incorrect PIN. \n";
		return;
	}
	
	cout << "Enter new PIN: ";
	cin >> newPin;
	
	accounts[userIndex].pin = newPin;
	
	cout << "PIN changed succesfully. \n";
}


int main() {
	int choice;
	
	while (true) {
		cout << "\n===== ATM SYSTEM =====\n";
		cout << "1. Create Account\n";
		cout << "2. Login\n";
		cout << "3. Exit\n";
		cout << "Choose option: ";
		cin >> choice;
		
		if (choice == 1) {
			createAccount();
		}
		
		else if (choice == 2) {
			int userIndex = login();
			
			if (userIndex != -1) {
				int subChoice;
				
				do {
					cout << "\n--- Banking Menu ---\n";
					cout << "1. Check Balance\n";
					cout << "2. Deposit\n";
					cout << "3. Withdraw\n";
					cout << "4. Transfer\n";
					cout << "5. Change PIN\n";
					cout << "6. Logout\n";
					cout << "Choose option: ";
					cin >> subChoice;
					
					if (subChoice == 1) checkBalance(userIndex);
					else if (subChoice == 2) depositMoney (userIndex);
					else if (subChoice == 3) withdrawMoney (userIndex);
					else if (subChoice == 4) transferMoney (userIndex);
					else if (subChoice == 5) changePin (userIndex);
					
				} while (choice != 6);
			}
		}
		else if (choice == 3) {
			cout << "Thank you for using ATM.\n";
			break;
		}
		else {
			cout << "Invalid option:\n";
		}
	}
	
	return 0;
}





































