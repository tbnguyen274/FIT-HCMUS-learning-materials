#include "lib.h"

int main() {
	// Client
	Client client("Lionel Messi", 1);
	cout << "Client Details:\n";
	client.display();

	// Account
	Account account(client, 2704, 1000.0);
	cout << "\nAccount Details:\n";
	account.display();

	account.deposit(500);
	cout << "\nAfter Deposit of 500:\n";
	account.display();

	account.withdraw(300);
	cout << "\nAfter Withdrawal of 300:\n";
	account.display();

	// Savings Account
	float interestRate = 0.05f;
	SavingsAccount savings(account, interestRate);
	cout << "\nSavings Account Details:\n";
	savings.display();

	// Apply interest
	savings.applyInterest();
	cout << "\nAfter Applying Interest:\n";
	savings.display();

	return 0;
}
