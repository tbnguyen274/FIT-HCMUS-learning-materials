#ifndef LIB_H
#define LIB_H

#include <iostream>
#include <string>

using namespace std;

class Client {
private:
	string name;
	int clientID;

public:
	Client();
	Client(const Client& client);
	Client(const string& name, const int& clientID);
	void display();
};

class Account {
protected:
	Client client;
	int accountNumber;
	float balance;

public:
	Account();
	Account(const Account& account);
	Account(const Client& client, const int& accountNumber, const float& balance);
	float getBalance();
	void deposit(const float& amount);
	void withdraw(const float& amount);
	void display();
};

class SavingsAccount : public Account {
private:
	float interestRate;

public:
	SavingsAccount();
	SavingsAccount(const SavingsAccount& account);
	SavingsAccount(const Account& account, const float& rate);
	SavingsAccount(const Client&, const int&, const float&, const float&);
	void applyInterest();
	void display();
};

#endif // !LIB_H
