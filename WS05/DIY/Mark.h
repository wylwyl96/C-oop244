#pragma once
//name:Yuelin Wen    stduent id:114379209
#ifndef SDDS_MARK_H_
#define SDDS_MARK_H_
#include <iostream>
namespace sdds {
	class Mark {
		int m_mark;
		void setEmpty();
	public:
		Mark();
		Mark(int number);

		operator int()const;
		Mark& operator+=(int RO);
		Mark& operator=(int RO);
		operator double()const;
		operator char()const;
		
	};
	int operator+=(int& LO, const Mark& RO);	
}
#endif