#pragma once
//name:Yuelin Wen email:ywen26@myseneca.ca
#ifndef BAR_H_
#define BAR_H_
namespace sdds {
	class Bar {
		char b_cstring[20];
		int b_val;
		char b_fill;

	public:
		void setEmpty();
		void set(const char* title, int bar);
		bool isValid()const;

		void draw()const;
	};
}
#endif