//name:Yuelin Wen email:ywen26@myseneca.ca
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Bar.h"
using namespace std;
namespace sdds {
	void Bar::setEmpty() {
		b_val = -1;
		b_cstring[0] = '\0';
	}
	void Bar::set(const char* title, int bar) {
		if (bar >= 0 && bar < 100)
		{
			strcpy(b_cstring, title);
			b_val = bar;
		}
	}
	bool Bar::isValid()const {
		bool valid = false;
		if (b_val >= 0) {
			valid = true;
		}
		return valid;
	}

	void Bar::draw()const {

		if (isValid())
		{
			cout.width(20);
			cout.fill('.');
			cout.setf(ios::left);
			cout << b_cstring;
			cout.unsetf(ios::left);
			cout << "|";

			cout.setf(ios::left);
			cout.width(50);
			for (int i = 0; i < b_val / 2; i++)
			{
				/*cout.put('=');*/
				cout << b_fill;
			}
			cout.unsetf(ios::left);
			cout << endl;

		}

	}
}