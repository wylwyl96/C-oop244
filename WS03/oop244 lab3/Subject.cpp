//name:Yuelin Wen yewn26@myseneca.ca
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include<cstdio>
#include "Subject.h"

using namespace std;
namespace sdds {
	char Subject::grade()const {
		char grade = '\0';
		if (m_mark >= 80 && m_mark <= 100)
		{
			grade = 'A';
		}
		else if (m_mark >= 70 && m_mark < 80)
		{
			grade = 'B';
		}
		else if (m_mark >= 60 && m_mark < 70)
		{
			grade = 'C';
		}
		else if (m_mark >= 50 && m_mark < 60)
		{
			grade = 'D';
		}
		else if (m_mark >= 0 && m_mark < 50)
		{
			grade = 'F';
		}
		return grade;
	}
	void Subject::setEmpty() {
		m_mark = -1;
		string m_code = "\0";
	}
	void Subject::set(const char* code, int mark) {
		if (m_mark < 0 || m_mark>0) {
			setEmpty();
		}
		m_mark = mark;
		strcpy(m_code, code);

	}
	float Subject::scale4()const {
		float grade = 0;
		if (m_mark >= 80 && m_mark <= 100)
		{
			grade = 4.0;
		}
		else if (m_mark >= 70 &&m_mark < 80)
		{
			grade = 3.0;
		}
		else if (m_mark >= 60 && m_mark < 70)
		{
			grade = 2.0;
		}
		else if (m_mark >= 50 && m_mark < 60)
		{
			grade = 1.0;
		}
		else if (m_mark >= 0 && m_mark < 50)
		{
			grade = 0.0;
		}
		return grade;
	}
	bool Subject::isValid()const {
		bool valid = false;
		if (m_mark >= 0)
		{
			valid = true;
		}
		return valid;
	}
	void Subject::display()const {
		if (isValid()) {
			cout.width(15);
			cout.setf(ios::left);
			cout << m_code;
			cout.unsetf(ios::left);


			cout.width(3);
			cout.setf(ios::right);
			cout << m_mark;
			cout.unsetf(ios::right);


			cout.width(10);
			cout.setf(ios::right);
			cout << grade() << endl;
			cout.unsetf(ios::right);



		}
	}
}