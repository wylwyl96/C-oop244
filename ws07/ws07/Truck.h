//name: yuelin wen
//email: ywen26@myseneca.ca
#pragma once
#ifndef TRUCK_H_
#define TRUCK_H_
#include <iostream>
#include "Vehicle.h"
namespace sdds {
	class Truck : public Vehicle
	{
		double m_capacity;
		double m_load = 0;
	public:
		Truck(const char* plate, int year, double capacity,const char* address, double load = 0);
		bool addCargo(double cargo);
		bool unloadCargo();
		std::ostream& write(std::ostream& os)const;
		std::istream& read(std::istream& in);
	};
	std::ostream& operator<<(std::ostream& os, const Truck& T);
	std::istream& operator>>(std::istream& istr, Truck& T);
}
#endif // !TRUCK_H_
