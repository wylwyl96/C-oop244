//name: yuelin wen
//email: ywen26@myseneca.ca
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Vehicle.h"
using namespace std;
namespace sdds {
	Vehicle::Vehicle(const char* plate, int year, const char* address)
	{
		strcpy(m_plate, plate);
		m_year = year;
		strcpy(m_address, address);
	}
	Vehicle::~Vehicle()
	{
	}
	void Vehicle::moveTo(const char* address)
	{
		if (!strstr(m_address, address))
		{
			cout << "|";
			cout.width(8);
			cout.setf(ios::right);
			cout << m_plate;
			cout.unsetf(ios::right);
			cout << "| |";
			cout.width(20);
			cout.setf(ios::right);
			cout << m_address;
			cout.unsetf(ios::right);
			cout << " ---> ";
			cout.width(20);
			cout.setf(ios::left);
			cout << address;
			cout.unsetf(ios::left);
			cout << "|" << endl;
			strcpy(m_address, address);
		}

	}
	ostream& Vehicle::write(ostream& os)const
	{
		os << "| " << m_year << " | " << m_plate << " | " << m_address;
		// TODO: insert return statement here
		return os;
	}
	istream& Vehicle::read(istream& in)
	{
		char plate[9];
		char address[64];
		int year;

		cout << "Built year: ";
		in >> year;
		cout << "License plate: ";
		in >> plate;
		cout << "Current location: ";
		in >> address;
		Vehicle temp(plate, year,address);
		*this = temp;
		// TODO: insert return statement here
		return in;
	}
	std::ostream& operator<<(std::ostream& os, const Vehicle& V)
	{
		V.write(os);
		// TODO: insert return statement here
		return os;
	}
	std::istream& operator>>(std::istream& istr, Vehicle& V)
	{
		V.read(istr);
		// TODO: insert return statement here
		return istr;
	}
}
