//name:Yuelin Wen    stduent id:114379209
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;
namespace sdds {
	void Account::setEmpty() {
		m_number = -1;
		m_balance = 0.0;
	}
	// New account
	Account::Account() {
		m_number = 0;
		m_balance = 0.0;
	}
	Account::Account(int number, double balance) {
		setEmpty();
		if (number >= 10000 && number <= 99999
			&& balance > 0) {
			m_number = number;
			m_balance = balance;
		}
	}
	std::ostream& Account::display() const {
		if (*this) {
			cout << "Acc#: ";
			if (~(*this))
				cout << "Not Set";
			else
				cout << " " << m_number << " ";
			cout << ", Balance: ";
			cout.width(12);
			cout.precision(2);
			cout.setf(ios::right);
			cout.setf(ios::fixed);
			cout << m_balance;
			cout.unsetf(ios::right);
			// I (Fardad) removed the "return cout", this was a mistake
			// (copied and pasted by mistake)
			// and had no effect to the execution of the program.
			// As mentioned before we should have only
			// one return statement in a function.
		}
		else {
			cout << "Invalid Account";
		}
		return cout;
	}

	void Account::InEmpty()
	{
		m_number = -1;
		m_balance = 0.0;
	}

	bool Account::isNew()
	{
		return m_number == 0;
	}

	bool Account::isValid()
	{
		return m_number >= 10000 && m_number <= 99999 && m_balance >= 0;
	}

	Account::operator bool() const
	{
		return m_number >= 0;
	}

	Account::operator int() const
	{
		return m_number;
	}

	Account::operator double() const
	{
		return m_balance;
	}

	bool Account::operator~()const
	{
		return m_number == 0;
	}

	Account& Account::operator=(int account)
	{
		if (m_balance>=0 && account >= 10000 && account <= 99999)
		{
			if (isNew())
			{
				m_number = account;
			}
		}
		else
		{
			InEmpty();
		}
		// TODO: insert return statement here
		return *this;
	}

	Account& Account::operator=(Account& account)
	{
		if (isValid())
		{
			if (account.m_number >= 10000 && account.m_number <= 99999 && account.m_balance >= 0)
			{
				m_balance = account.m_balance;
				account.m_balance = 0;
			}
			
		}
		// TODO: insert return statement here
		return *this;
	}

	Account& Account::operator-=(double balance)
	{
		if (isValid() && balance <= m_balance && balance >= 0)
		{
			m_balance -= balance;
		}
		// TODO: insert return statement here
		return *this;
	}

	Account& Account::operator+=(double balance)
	{
		if (isValid() && balance >= 0)
		{
			m_balance += balance;
		}
		// TODO: insert return statement here
		return *this;
	}

	double operator+(const Account& LO, const Account& RO)
	{
		double sum = 0.0;
		if (int(LO) >= 10000 && int(LO) <= 99999 && double(RO) >= 0.0 && int(RO) >= 10000 && int(LO) <= 99999 && double(RO) >= 0.0)
		{
			sum = double(LO) + double(RO);
		}
		return sum;
	}

	double operator+=(double& LO, const Account& RO)
	{
		if (double(RO) >= 0.0 && int(RO) >= 10000 && int(LO) <= 99999 && double(RO) >= 0.0)
		{
			LO += double(RO);
		}
		return LO;
	}

}