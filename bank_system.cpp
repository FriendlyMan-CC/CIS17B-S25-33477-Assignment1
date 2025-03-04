#include <iostream>
using namespace std;

void firstWelcome(); // Functions
void secondWelcome();

class BankAccount {
private:
	string accountHolderName;
	int accountNumber;
	double balance;

public:

	BankAccount(string HolderName, double constructBalance) {
		accountHolderName = HolderName;
		balance = constructBalance;
	}

	// Setters to set the private members with some user information
	void setAccountHolderName(string name) {
		accountHolderName = name;
	}
	void deposit(double amount) {

		balance += amount;
	}
	void withdraw(double amount) {
		balance -= amount;
	}


	// Getters to get the information from private members
	string displayAccountholderName() {
		return accountHolderName;
	}
	double displayBalance() {
		return balance;
	}

};

int main() {

	BankAccount user("N/A", 0); // Constructor to add default values
	
	// Declarations
	string holderName;
	double placeHolderDouble; // This is a temporary variable that will be recycled. Makes it easier so I don't have to keep on making new variables
	int caseNumbers;
	int userChoice = 0;

	firstWelcome();

	
		
		cout << endl;
		cout << "Enter your choice: ";
		while (true) { // Try catch block for errors. I put an explanation of the try catch block on the try catch block from case 1.

			cin >> userChoice;

			try {
				if (cin.fail()) {
					throw invalid_argument("Error! Input must be Numbers! Please Try Again: ");
				}
				else if (userChoice < 1 || userChoice > 5) {
					throw invalid_argument("Error! Input must be between 1-5! Please Try Again: ");
				}
				break;
			}
			catch (const invalid_argument& e) {
				cerr << e.what() << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}

	do { // Program uses a do while loop. If user enters 5. Then the loop ends.
		if (userChoice == 5) {
			break;
		}


		switch (userChoice) { // Cases that are used to give the user a choice by inputting numbers. 
		case 1:	// If user wants to create an account

			cout << endl;
			cout << "Enter your account holder name: ";
			cin >> holderName;
			user.setAccountHolderName(holderName);	// store name in class
			cout << "Enter initial deposit: ";

			while (true) { // While loop to ensure negative numbers do not get an error. 
				cin >> placeHolderDouble;
				try {
					
					if (cin.fail()) { // Throws two arguments. One for a negative number and the other if the user uses letters.
						throw invalid_argument("Error! Input must be a number! Please try again");
					}
					else if (placeHolderDouble < 0) {
						throw invalid_argument("Error! Numbers must be positve! Please try again: ");

					}
					
					cin.clear(); // Resets cin.fail() status
					cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Forces machine to ignore the remaining user input so it does not cause infinite loop
					break; // If the input is valid, then the break will cause program to move on from loop
					
				}
				catch (const invalid_argument& e) { // Catches the error from user input
					cerr << e.what() << endl; // Will say message from throw invalid_argument
					cin.clear(); // Resets cin.fail() status
					cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Forces machine to ignore the remaining user input so it does not cause infinite loop
				}

			}



			user.deposit(placeHolderDouble); // store initial deposit in class
			cout << endl << "Account Created Successfully!" << endl;
			break;

		case 2: // User selects to deposit
			cout << endl;
			cout << "How much do you want to deposit?: ";

			while (true) { // While loop to ensure negative numbers do not get an error. 
				cin >> placeHolderDouble;
				try {

					if (cin.fail()) { // Throws two arguments. One for a negative number and the other if the user uses letters.
						throw invalid_argument("Error! Input must be a number! Please try again");
					}
					else if (placeHolderDouble < 0) {
						throw invalid_argument("Error! Numbers must be positve! Please try again: ");
					}

					break; // If the input is valid, then the break will cause program to move on from loop

				}
				catch (const invalid_argument& e) { // Catches the error from user input
					cerr << e.what() << endl; // Will say message from throw invalid_argument
					cin.clear(); // Resets cin.fail() status
					cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Forces machine to ignore the remaining user input so it does not cause infinite loop
				}

			}

			user.deposit(placeHolderDouble);  // Deposit money to class
			cout << "Deposit successful! New balance: $" << user.displayBalance(); // Show the result of the deposit
			cout << endl;

			break;

		case 3: // User selects to withdraw
			cout << endl;
			cout << "How much do you want to withdraw? ";
			
			while (true) { // Try catch block used to throw errors similar to the first one

				try {
					cin >> placeHolderDouble;
					
					if (placeHolderDouble < 0) {
						throw invalid_argument("Error! Cannot withdraw Negative Amounts. Please Try Again: ");
					}
					else if (placeHolderDouble > user.displayBalance()) {
						throw invalid_argument("Error! Cannot withdraw more than balance. Please Try Again!: ");
					}
					else if (cin.fail()) {
						throw invalid_argument("Error! Input must be Numbers! Please Try Again: ");
					}
					break;
				}
				catch (const invalid_argument& e) {
					cerr << e.what() << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}

			user.withdraw(placeHolderDouble);
			cout << "Withdraw Successful! New Balance: $" << user.displayBalance();

			cout << endl;
			break;
		case 4:
			cout << endl;
			cout << "Current Balance: $" << user.displayBalance();
			cout << endl;
			break;
		}

		secondWelcome(); // Purpose is to match output choices from canvas example. Since create account gets removed. Everything gets moved up.
						// For instance, Originally it was 2. Deposit Money, now it is 1. Deposit money
		cout << endl << endl;
		cout << "Enter your choice: ";

		while (true) { // Another try catch block for errors

			cin >> userChoice;
			
			try {
				if (cin.fail()) {
					throw invalid_argument("Error! Input must be Numbers! Please Try Again: ");
				}
				else if (userChoice < 1 || userChoice > 4) {
					throw invalid_argument("Error! Input must be between 1-4! Please Try Again: ");
				}
				break;
			}
			catch (const invalid_argument& e) {
				cerr << e.what() << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}
		
		userChoice += 1; // This is to help with accomodate user choice since the menu is moved around.

	} while (userChoice != 5);

	cout << endl << endl; 
	cout << "Thank you for using the Norco College Simple Banking System!";
	cout << endl;

	return 0;
}

void firstWelcome() { // First Variation of welcoming the User
	cout << "Welcome to the Norco College Simple Banking System!" << endl;
	cout << "What would you like to do? (1-5)" << endl;
	cout << "1. Create Account" << endl;
	cout << "2. Deposit Money" << endl;
	cout << "3. Withdraw Money" << endl;
	cout << "4. Check Balance" << endl;
	cout << "5. Exit" << endl;
}

void secondWelcome() { // Second variation of welcoming the User. 
	cout << endl;
	cout << "What would you like to do? (1-4)?" << endl;
	cout << "1. Deposit Money" << endl;
	cout << "2. Withdraw Mondey" << endl;
	cout << "3. Check Balance" << endl;
	cout << "4. Exit";
}


