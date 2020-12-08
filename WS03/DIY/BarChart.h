//name:Yuelin Wen email:ywen26@myseneca.ca
#ifndef BARCHART_H_
#define BARCHART_H_
#include "Bar.h"
namespace sdds {
	class BarChart {
		char* b_title;
		Bar* b_bars;

		char b_fill;
		int b_noOfBars;
		int b_noOfBarsAdded;

		bool isValid()const;
	public:
		void init(const char* title, int noOfSampels, char fill);
		bool add(const char* bar_title, int value);
		void draw()const;
		void deallocate();
	};
}
#endif
