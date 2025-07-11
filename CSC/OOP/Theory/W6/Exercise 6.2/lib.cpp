#include "lib.h"

Screen::Screen() {
	id = 0;
	totalSeats = 0;
	seatAvailability = nullptr;
	standardPrice = 0.0;
	revenue = 0.0;
}

Screen::Screen(const Screen& screen) {
	id = screen.id;
	totalSeats = screen.totalSeats;
	standardPrice = screen.standardPrice;
	revenue = screen.revenue;
	seatAvailability = new bool[totalSeats];

	for (int i = 0; i < totalSeats; i++) {
		seatAvailability[i] = screen.seatAvailability[i];
	}
}

Screen::Screen(int id, int totalSeats, double standardPrice) {
	this->id = id;
	this->totalSeats = totalSeats;
	this->standardPrice = standardPrice;
	revenue = 0.0;
	seatAvailability = new bool[totalSeats];
	for (int i = 0; i < totalSeats; i++) {
		seatAvailability[i] = true; // All seats are available initially
	}
}

Screen::~Screen() {
	delete[] seatAvailability;
}

Screen& Screen::operator=(const Screen& screen) {
	if (this != &screen) {
		delete[] seatAvailability;

		id = screen.id;
		totalSeats = screen.totalSeats;
		standardPrice = screen.standardPrice;
		revenue = screen.revenue;
		seatAvailability = new bool[totalSeats];

		for (int i = 0; i < totalSeats; i++) {
			seatAvailability[i] = screen.seatAvailability[i];
		}
	}
	return *this;
}

bool Screen::isAvailable(int seatNumber) {
	if (seatNumber < 0 || seatNumber >= totalSeats) {
		return false; // Invalid seat number
	}
	return seatAvailability[seatNumber - 1];
}

void Screen::bookSeat(int seatNumber) {
	if (isAvailable(seatNumber)) {
		seatAvailability[seatNumber - 1] = false;
		cout << "Seat " << seatNumber << " booked successfully." << endl;
	}
	else {
		cout << "Seat " << seatNumber << " is already booked." << endl;
	}
}

double Screen::getPrice() {
	return standardPrice;
}

void Screen::calculateRevenue() {
	revenue = 0.0;
	for (int i = 0; i < totalSeats; i++) {
		if (!seatAvailability[i]) {
			revenue += standardPrice;
		}
	}
}

double Screen::getRevenue() {
	return revenue;
}

void Screen::displayScreen() {
	cout << "\n================== Screen Information ===============" << endl;
	cout << "Screen ID: " << id << endl;
	cout << "Total Seats: " << totalSeats << endl;
	cout << "Standard Price: $" << standardPrice << endl;
	cout << "Revenue: $" << revenue << endl;
	cout << "Seat Availability: ";
	for (int i = 0; i < totalSeats; i++) {
		cout << (seatAvailability[i] ? "0" : "1") << " ";
	}
	cout << endl;
}

// ============= VIPScreen Class =============
VIPScreen::VIPScreen() : Screen() {
	chargeRate = 0.0;
	numServices = 0;
	extraServices = nullptr;
}

VIPScreen::VIPScreen(const VIPScreen& screen) : Screen(screen) {
	chargeRate = screen.chargeRate;
	numServices = screen.numServices;
	extraServices = new string[numServices];
	for (int i = 0; i < numServices; i++) {
		extraServices[i] = screen.extraServices[i];
	}
}

VIPScreen::VIPScreen(int id, int totalSeats, double standardPrice, double chargeRate, string* extraServices, int numServices) : Screen(id, totalSeats, standardPrice) {
	this->chargeRate = chargeRate;
	this->numServices = numServices;
	this->extraServices = new string[numServices];

	for (int i = 0; i < numServices; i++) {
		this->extraServices[i] = extraServices[i];
	}
}

VIPScreen::VIPScreen(double chargeRate, string* extraServices, int numServices) : Screen() {
	this->chargeRate = chargeRate;
	this->numServices = numServices;
	this->extraServices = new string[numServices];
	for (int i = 0; i < numServices; i++) {
		this->extraServices[i] = extraServices[i];
	}
}

VIPScreen::~VIPScreen() {
	delete[] extraServices;
}

VIPScreen& VIPScreen::operator=(const VIPScreen& screen) {
	if (this != &screen) {
		Screen::operator=(screen); // Call base class assignment operator
		delete[] extraServices;

		chargeRate = screen.chargeRate;
		numServices = screen.numServices;
		extraServices = new string[numServices];

		for (int i = 0; i < numServices; i++) {
			extraServices[i] = screen.extraServices[i];
		}
	}
	return *this;
}

void VIPScreen::addService(const string& service) {
	string* temp = new string[numServices + 1];
	for (int i = 0; i < numServices; i++) {
		temp[i] = extraServices[i];
	}
	temp[numServices] = service;
	delete[] extraServices;
	extraServices = temp;
	numServices++;
}

double VIPScreen::getPrice() {
	return standardPrice * (1 + chargeRate);
}

void VIPScreen::calculateRevenue() {
	revenue = 0.0;
	for (int i = 0; i < totalSeats; i++) {
		if (!seatAvailability[i]) {
			revenue += getPrice();
		}
	}
}

void VIPScreen::displayScreen() {
	Screen::displayScreen();
	cout << "Charge Rate: " << chargeRate << endl;
	cout << "Extra Services: ";
	for (int i = 0; i < numServices; i++) {
		cout << extraServices[i] << " ";
	}
	cout << endl;
}

