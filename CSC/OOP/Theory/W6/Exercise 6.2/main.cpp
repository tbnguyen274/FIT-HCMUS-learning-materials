#include "lib.h"

// Test 
int main() {
	// Create a Screen object
	Screen screen(1, 20, 100.0);
	screen.bookSeat(2);
	screen.bookSeat(5);
	screen.bookSeat(2);
	screen.calculateRevenue();
	screen.displayScreen();
	cout << endl;

	// Create a VIPScreen object
	string services[] = { "Catering", "VIP Lounge" };
	VIPScreen vipScreen(2, 10, 150.0, 0.2, services, 2);
	vipScreen.bookSeat(3);
	vipScreen.addService("Private Parking");
	vipScreen.calculateRevenue();
	vipScreen.bookSeat(3);
	vipScreen.displayScreen();
	cout << endl;
	return 0;
}