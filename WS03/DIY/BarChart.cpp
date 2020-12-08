//name:Yuelin Wen email:ywen26@myseneca.ca
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "BarChart.h"
using namespace std;
namespace sdds {
	bool BarChart::isValid()const {
		bool valid = false;
		if (b_title != nullptr && b_bars != nullptr && b_fill != '\0')
		{
			valid = true;

		}
		return valid;
	}
	void BarChart::init(const char* title, int noOfSampels, char fill) {
		if (title[0] != '\0' || noOfSampels >= 0 || fill != '\0')
		{
			b_noOfBarsAdded = 0;
			b_noOfBars = noOfSampels;
			b_fill = fill;
			b_title = new char[strlen(title) + 1];
			strcpy(b_title, title);
			b_bars = new Bar[b_noOfBars];
		}
	}
	bool BarChart::add(const char* bar_title, int value) {
		bool add = true;
		if (b_noOfBarsAdded < b_noOfBars)
		{
			b_bars[b_noOfBarsAdded].set(bar_title, value);
			b_noOfBarsAdded++;
		}
		else
		{
			add = false;
		}
		return add;
	}
	void BarChart::draw()const {
		if (b_noOfBarsAdded==b_noOfBars)
		{
			cout << b_title << endl;
			cout <<"-----------------------------------------------------------------------"<< endl;
			for (int i = 0; i < b_noOfBarsAdded; i++)
			{
				b_bars[i].draw();
			}
			cout <<"-----------------------------------------------------------------------"<< endl;
		}
		else
		{
			cout << "Invalid Chart!" << endl;
		}
	}
	void BarChart::deallocate() {
		delete[] b_title;
		b_title = nullptr;
		delete[] b_bars;
		b_bars = nullptr;
	}
}