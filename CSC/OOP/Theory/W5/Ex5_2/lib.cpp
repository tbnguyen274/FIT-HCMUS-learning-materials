#include "lib.h"

Client::Client() {
	name = "";
	clientID = 0;
}

Client::Client(const Client& client) {
	this->name = client.name;
	this->clientID = client.clientID;
}

Client::Client(const string& name, const int& clientID) {
	this->name = name;
	this->clientID = clientID;
}

void Client::display() {
	cout << "Name: " << name << endl;
	cout << "ID: " << clientID << endl;
}

Account::Account() {
	accountNumber = 0;
	balance = 0;
}

Account::Account(const Account& account) {
	this->client = account.client;
	this->accountNumber = account.accountNumber;
	this->balance = account.balance;
}

Account::Account(const Client& client, const int& accountNumber, const float& balance) {
	this->client = client;
	this->accountNumber = accountNumber;
	this->balance = balance;
}

float Account::getBalance() {
	return balance;
}

void Account::deposit(const float& amount) {
	balance += amount;
}

void Account::withdraw(const float& amount) {
	if (amount <= balance) {
		balance -= amount;
	}
}

void Account::display() {
	client.display();
	cout << "Account Number: " << accountNumber << endl;
	cout << "Balance: " << balance << endl;
}

SavingsAccount::SavingsAccount() : Account() {
	interestRate = 0.0f;
}

SavingsAccount::SavingsAccount(const SavingsAccount& account) : Account(account) {
	this->interestRate = account.interestRate;
}

SavingsAccount::SavingsAccount(const Account& account, const float& interestRate) : Account(account) {
	this->interestRate = interestRate;
}

SavingsAccount::SavingsAccount(const Client& client, const int& accountNumber, const float& balance, const float& interestRate) :
	Account(client, accountNumber, balance) {
	this->interestRate = interestRate;
}

void SavingsAccount::applyInterest() {
	balance += balance * interestRate;
}

void SavingsAccount::display() {
	Account::display();
	cout << "Interest Rate: " << interestRate << endl;
}