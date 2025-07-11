#ifndef LIB_H
#define LIB_H

#include <iostream>
#include <string>


using namespace std;

class Screen {
protected:
	int id;
	int totalSeats;
	bool* seatAvailability;
	double standardPrice;
	double revenue;

public:
	Screen();
	Screen(const Screen&);
	Screen(int id, int totalSeats, double standardPrice);
	~Screen();
	Screen& operator=(const Screen&);

	bool isAvailable(int seatNumber);
	void bookSeat(int seatNumber);
	double getPrice();
	void calculateRevenue();
	double getRevenue();
	void displayScreen();

};

class VIPScreen : public Screen {
private:
	double chargeRate;
	string* extraServices;
	int numServices;
public:
	// constructors
	VIPScreen();

	// copy constructor
	VIPScreen(const VIPScreen&);
	VIPScreen(int id, int totalSeats, double standardPrice, double chargeRate, string* extraServices, int numServices);
	VIPScreen(double chargeRate, string* extraServices, int numServices);

	// destructor
	~VIPScreen();

	// operators
	VIPScreen& operator=(const VIPScreen&);

	void addService(const string& service);
	double getPrice();
	void calculateRevenue();
	void displayScreen();

};

#endif