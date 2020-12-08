//name:yuelin wen  email:ywen26@myseneca.ca
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <fstream>
#include "Numbers.h"
using namespace std;
namespace sdds {


	Numbers::Numbers() {
		setEmpty();
		m_isOriginal = false;
	}

	Numbers::Numbers(const char* filename) {
		setEmpty();
		m_isOriginal = true;
		setFilename(filename);
		m_numCount = numberCount();
		if (m_numCount == 0 || !load()) {
			delete[] m_numbers;
			delete[] m_filename;
			setEmpty();
			m_isOriginal = false;
		}
		else {
			sort();
		}
	}

	Numbers::~Numbers() {
		save();
		delete[] m_numbers;
		delete[] m_filename;
	}

	Numbers::Numbers(const Numbers& N)
	{
		setEmpty();
		m_isOriginal = false;
		m_numCount = N.m_numCount;
		if (N.m_numbers != nullptr)
		{
			m_numbers = new double[m_numCount];
			for (int i = 0; i < m_numCount; i++)
			{
				m_numbers[i] = N.m_numbers[i];
			}
		}
		else
		{
			m_numbers = nullptr;
		}
	}

	Numbers& Numbers::operator=(const Numbers& N)
	{
		if (this != &N)
		{
			m_numCount = N.m_numCount;
			delete[] m_numbers;
			if (N.m_numbers != nullptr)
			{
				m_numbers = new double[m_numCount];
				for (int i = 0; i < m_numCount; i++)
				{
					m_numbers[i] = N.m_numbers[i];
				}

			}
			else
			{
				m_numbers = nullptr;
			}
		}
		// TODO: insert return statement here
		return *this;
	}

	int Numbers::numberCount() const
	{
		int num = 0;
		char ch;
		ifstream f;
		f.open(m_filename);
		if (f.is_open())
		{
			while (f.get(ch)) {
				if (ch == '\n')
				{
					num++;
				}
			}
		}
		return num;
	}

	bool Numbers::load()
	{
		bool flag = false;
		int num = 0;
		ifstream f;
		if (m_numCount > 0)
		{
			delete[] m_numbers;
			m_numbers = new double[m_numCount];
			f.open(m_filename);
			if (f.is_open()) {

				for (int i = 0; i < m_numCount && f; i++)
				{
					f >> m_numbers[i];
					num++;
				}

			}
		}
		if (num == m_numCount)
		{
			flag = true;
		}
		return flag;
	}

	void Numbers::save()
	{
		if (m_isOriginal && !isEmpty())
		{
			ofstream f(m_filename);
			if (f.is_open())
			{
				for (int i = 0; i < m_numCount; i++)
				{
					f << m_numbers[i] << endl;
				}
			}
		}
	}

	Numbers& Numbers::operator+=(double d)
	{
		double* temp;
		temp = new double[m_numCount + 1];
		for (int i = 0; i < m_numCount; i++)
		{
			temp[i] = m_numbers[i];
		}
		
		temp[m_numCount] = d;
		m_numCount += 1;
		delete[] m_numbers;
		m_numbers = temp;
		sort();

		// TODO: insert return statement here
		return *this;
	}

	ostream& Numbers::display(ostream& ostr) const
	{
		if (!isEmpty())
		{
			ostr << "=========================" << endl;
			if (m_isOriginal)
			{
				ostr << m_filename << endl;
			}
			else
			{
				ostr << "*** COPY ***" << endl;
			}
			for (int i = 0; i < m_numCount - 1; i++)
			{
				ostr << m_numbers[i] << ", ";
			}
			ostr << m_numbers[m_numCount - 1] << endl;
			ostr << "-------------------------" << endl;
			ostr << "Total of " << m_numCount << " number(s)" << endl;
			ostr << "Largest number:  " << max() << endl;
			ostr << "Smallest number: " << min() << endl;
			ostr << "Average :        " << average() << endl;
			ostr << "=========================";

		}
		else
		{
			ostr << "Empty list";
		}
		// TODO: insert return statement here
		return ostr;
	}

	bool Numbers::isEmpty() const {
		return m_numbers == nullptr;
	}

	void Numbers::setEmpty() {
		m_numbers = nullptr;
		m_filename = nullptr;
		m_numCount = 0;
	}
	void Numbers::setFilename(const char* filename) {
		delete[] m_filename;
		m_filename = new char[strlen(filename) + 1];
		strcpy(m_filename, filename);
	}
	void Numbers::sort() {
		int i, j;
		double temp;
		for (i = m_numCount - 1; i > 0; i--) {
			for (j = 0; j < i; j++) {
				if (m_numbers[j] > m_numbers[j + 1]) {
					temp = m_numbers[j];
					m_numbers[j] = m_numbers[j + 1];
					m_numbers[j + 1] = temp;
				}
			}
		}
	}

	double Numbers::average() const {
		double aver = 0.0;
		if (!isEmpty()) {
			for (int i = 0; i < m_numCount; i++)
				aver += m_numbers[i];
			aver = aver / m_numCount;
		}
		return aver;
	}
	double Numbers::min() const {
		double minVal = 0.0;
		if (!isEmpty()) {
			minVal = m_numbers[0];
			for (int i = 1; i < m_numCount; i++)
				if (minVal > m_numbers[i]) minVal = m_numbers[i];
		}
		return minVal;
	}
	double Numbers::max() const {
		double maxVal = 0.0;
		if (!isEmpty()) {
			maxVal = m_numbers[0];
			for (int i = 1; i < m_numCount; i++)
				if (maxVal < m_numbers[i]) maxVal = m_numbers[i];
		}
		return maxVal;
	}

	ostream& operator<<(ostream& os, const Numbers& N)
	{
		N.display(os);
		// TODO: insert return statement here
		return os;
	}
	istream& operator>>(istream& istr, Numbers& N)
	{
		double d;
		istr >> d;
		N += d;

		// TODO: insert return statement here
		return istr;
	}
}