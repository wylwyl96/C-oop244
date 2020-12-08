//name:Yuelin Wen    stduent id:114379209
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Mark.h"

using namespace std;
namespace sdds {
	void sdds::Mark::setEmpty()
	{
		m_mark = 0;
	}

	sdds::Mark::Mark()
	{
		setEmpty();
	}

	sdds::Mark::Mark(int number)
	{
		m_mark = number;
	}

	Mark::operator int() const
	{
		int val;
		if (m_mark >= 0 && m_mark <= 100)
		{
			val = m_mark;
		}
		else
		{
			val = 0;
		}
		return val;
	}

	Mark& Mark::operator+=(int RO)
	{
		if (m_mark < 0 && m_mark>100)
		{
			setEmpty();
		}
		else
		{
			if (RO >= 0 && RO <= 100)
			{
				m_mark += RO;
				if (m_mark < 0 && m_mark>100)
				{
					setEmpty();
				}
			}
		}
		return *this;
	}

	Mark& Mark::operator=(int RO)
	{
		m_mark = RO;
		// TODO: insert return statement here
		return *this;
	}

	Mark::operator double() const
	{
		double scale;
		if (m_mark >= 0 && m_mark < 50)
		{
			scale = 0.0;
		}
		else if (m_mark >= 50 && m_mark < 60)
		{
			scale = 1.0;
		}
		else if (m_mark >= 60 && m_mark < 70)
		{
			scale = 2.0;
		}
		else if (m_mark >= 70 && m_mark < 80)
		{
			scale = 3.0;
		}
		else if (m_mark >= 80 && m_mark < 100)
		{
			scale = 4.0;
		}
		else
		{
			scale = 0.0;
		}
		return scale;
	}

	Mark::operator char() const
	{
		double grade;
		if (m_mark >= 0 && m_mark < 50)
		{
			grade = 'F';
		}
		else if (m_mark >= 50 && m_mark < 60)
		{
			grade = 'D';
		}
		else if (m_mark >= 60 && m_mark < 70)
		{
			grade = 'C';
		}
		else if (m_mark >= 70 && m_mark < 80)
		{
			grade = 'B';
		}
		else if (m_mark >= 80 && m_mark < 100)
		{
			grade = 'A';
		}
		else
		{
			grade = 'X';
		}
		return grade;
	}

	int operator+=(int& LO, const Mark& RO)
	{
		if (int(RO) >= 0 && int(RO) <= 100)
		{
			LO += int(RO);
		}
		return LO;
	}

}

