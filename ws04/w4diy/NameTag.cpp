//name:yuelin wen    email:ywen26@myseneca.ca
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include"NameTag.h"
using namespace std;
namespace sdds {
	void NameTag::setName(const char* Cstr)
	{
		if (Cstr != nullptr)
		{
			m_nametag = nullptr;
			m_nametag = new char[strlen(Cstr) + 1];
			strcpy(m_nametag, Cstr);
		}
		else
		{
			setUnusable();
		}
	}

	void NameTag::setUnusable()
	{
		m_nametag = nullptr;
		m_extnum = -1;
	}

	bool NameTag::isUnusable() const
	{
		bool flag = false;
		if (m_extnum != -1)
		{
			if (m_extnum < 10000 || m_extnum>99999 || m_nametag == nullptr)
			{
				flag = true;
			}
		}
		else
		{
			if (m_nametag == nullptr)
			{
				flag = true;
			}
		}

		return flag;
	}

	NameTag::NameTag()
	{
		setUnusable();
	}

	NameTag::NameTag(const char* nametag)
	{
		if (nametag == nullptr)
		{
			setUnusable();
		}
		else
		{
			setName(nametag);
			m_extnum = -1;
		}

	}

	NameTag::NameTag(const char* nametag, int num)
	{
		if (nametag == nullptr || num < 10000 || num>99999)
		{
			setUnusable();
		}
		else
		{
			setName(nametag);
			m_extnum = num;
		}

	}

	NameTag::~NameTag()
	{
		delete[] m_nametag;
		m_nametag = nullptr;

	}

	NameTag& NameTag::read()
	{
		char yn;
		m_nametag = nullptr;
		m_nametag = new char[100];
		cout << "Please enter the name: ";
		cin.getline(m_nametag, 100, '\n');
		cout << "Would you like to enter an extension? (Y)es/(N)o: ";
		cin.get(yn);
		if (yn == 'y' || yn == 'Y')
		{
			cout << "Please enter a 5 digit phone extension: ";
			cin >> m_extnum;
			while (m_extnum < 10000 || m_extnum>99999)
			{
				cout << "Invalid value [10000<=value<=99999]: ";
				cin >> m_extnum;
			}
		}
		else if (yn == 'n' || yn == 'N')
		{
			m_extnum = -1;
		}
		else
		{
			m_extnum = -1;

		}
		cin.clear();
		cin.ignore(100, '\n');
		// TODO: insert return statement here
		return *this;
	}

	std::ostream& NameTag::print()const
	{
		if (isUnusable())
		{
			cout << "EMPTY NAMETAG!" << endl;
		}
		else
		{
			if (strlen(m_nametag) <= 20)
			{
				cout << "************************" << endl;
				cout << "*                      *" << endl;

				cout << "* ";
				cout.width(20);
				cout.fill(' ');
				cout.setf(ios::left);
				cout << m_nametag << " *" << endl;

				cout << "*                      *" << endl;
				cout << "* Extension: ";
				cout.width(10);
				cout.fill(' ');
				cout.setf(ios::left);
				if (m_extnum == -1)
				{

					cout << "N/A" << "*" << endl;
				}
				else
				{

					cout << m_extnum << "*" << endl;
				}
				cout << "*                      *" << endl;
				cout << "************************" << endl;
			}
			else
			{
				cout << "********************************************" << endl;
				cout << "*                                          *" << endl;

				cout << "* ";
				cout.width(44);
				cout.fill(' ');

				cout.setf(ios::left);
				cout.write(m_nametag, 40);
				cout.width(2);
				cout.unsetf(ios::left);
				cout.setf(ios::right);
				cout << "*" << endl;
				cout.unsetf(ios::right);

				cout << "*                                          *" << endl;


				cout << "* Extension: ";
				cout.width(30);
				cout.fill(' ');
				cout.setf(ios::left);
				if (m_extnum == -1)
				{
					cout << "N/A" << "*" << endl;
				}
				else
				{
					cout << m_extnum << "*" << endl;
				}
				cout.unsetf(ios::left);
				cout << "*                                          *" << endl;
				cout << "********************************************" << endl;
			}

		}
		// TODO: insert return statement here
		return cout;
	}


}