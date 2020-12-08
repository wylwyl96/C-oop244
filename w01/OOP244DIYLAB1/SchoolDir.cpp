#include <iostream>
#include "School.h"
using namespace std;
using namespace dir;


// flushes the keyboard
void flushkeys() {
	while (cin.get() != '\n');
}

// returns true if user enter y or Y
bool yes() {
	char ch = cin.get();
	flushkeys();
	return ch == 'y' || ch == 'Y';
}

int main() {
	bool done = false;
	char scode[10];
	loadSchool();
	cout << "Seneca School Extension search." << endl << endl;
	while (!done) {
		cout << "Enter the School code: ";
		cin >> scode;
		flushkeys();
		DisplayExt(scode);
		cout << "Do another search? (Y)es: ";
		done = !yes();
		cout << endl;
	}
	cout << "Goodbye!" << endl;
	return 0;
}