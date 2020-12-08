//name: yuelin wen
//email: ywen26@myseneca.ca
#pragma once
#ifndef VEHICLE_H_
#define VEHICLE_H_
#include <iostream>
namespace sdds {
	class Vehicle
	{
	protected:
		char m_plate[9];
		char m_address[64];
		int m_year;

	public:
		Vehicle(const char* plate, int year, const char* address = "Factory");
		~Vehicle();
		void moveTo(const char* address);
		std::ostream& write(std::ostream& os)const;
		std::istream& read(std::istream& in);
	};
	std::ostream& operator<<(std::ostream& os, const Vehicle& V);
	std::istream& operator>>(std::istream& istr, Vehicle& V);
}
#endif // !VEHICLE_H_
