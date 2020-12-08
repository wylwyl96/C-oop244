//name: yuelin wen
//email: ywen26@myseneca.ca
#define _CRT_SECURE_NO_WARNINGS
#include "Truck.h"
#include <cstring>
using namespace std;
namespace sdds {
	Truck::Truck(const char* plate, int year, double capacity, const char* address, double load) :Vehicle(plate, year)
	{
		m_load = load;
		m_capacity = capacity;
		if (strstr(address,"Toronto HQ"))
		{
			strcpy(m_address, "Factory");
			moveTo("Toronto HQ");
		}
		strcpy(m_address, address);
		//Vehicle::moveTo(address);
	}
	bool Truck::addCargo(double cargo)
	{
		bool flag = true;
		
		if (m_load >= m_capacity)
		{
			m_load = m_capacity;
			flag = false;
		}
		else
		{
			m_load += cargo;
			if (m_load >= m_capacity)
			{
				m_load = m_capacity;
			}
		}
		return flag;
	}
	bool Truck::unloadCargo()
	{
		bool flag = false;
		if (m_load != 0)
		{
			m_load = 0;
			flag = true;
		}
		return flag;
	}
	ostream& Truck::write(ostream& os)const
	{
		os << "| " << m_year << " | " << m_plate << " | " << m_address << " | " << m_load << "/" << m_capacity;
		// TODO: insert return statement here
		return os;
	}
	std::istream& Truck::read(std::istream& in)
	{
		int year;
		char plate[9];
		char address[64];
		double capacity;
		double cargo;

		cout << "Built year: ";
		in >> year;
		cout << "License plate: ";
		in >> plate;
		cout << "Current location: ";
		in >> address;
		cout << "Capacity: ";
		in >> capacity;
		cout << "Cargo: ";
		in >> cargo;
		Truck temp(plate, year, capacity, address, cargo);
		*this = temp;
		// TODO: insert return statement here
		return in;
	}
	std::ostream& operator<<(std::ostream& os, const Truck& T)
	{
		T.write(os);
		// TODO: insert return statement here
		return os;
	}
	std::istream& operator>>(std::istream& istr, Truck& T)
	{
		T.read(istr);
		// TODO: insert return statement here
		return istr;
	}
}
