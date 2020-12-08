//yuelin wen     ywen26@myseneca.ca
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Box.h"
using namespace std;
namespace sdds {
	void Box::setName(const char* Cstr) {
		if (Cstr != nullptr)
		{
			m_contentName = nullptr;
			m_contentName = new char[strlen(Cstr) + 1];
			strcpy(m_contentName, Cstr);
		}
	}
	void Box::setUnusable() {
		m_contentName = nullptr;
		m_width = -1;
		m_height = -1;
		m_length = -1;
		m_contentVolume = -1;
	}
	bool Box::isUnusable()const {
		bool flag = true;
		if (m_width != -1)
		{
			if (m_width >= 5 && m_width <= 36 && m_length >= 5 && m_length <= 36 && m_height >= 5 && m_height <= 36)
			{
				flag = false;
			}
		}

		return flag;
	}
	bool Box::hasContent()const {
		return quantity() > 0;
	}
	Box::Box() {
		m_width = 12;
		m_height = 12;
		m_length = 12;
		m_contentName = NULL;
		m_contentVolume = 0;
	}
	Box::Box(int sideLength, const char* contentName) {
		m_contentName = nullptr;
		if (sideLength >= 5 && sideLength <= 36)
		{
			m_width = sideLength;
			m_height = sideLength;
			m_length = sideLength;
			m_contentVolume = 0;
			setName(contentName);
		}
		else
		{
			setUnusable();
		}
	}
	Box::Box(int width, int height, int length, const char* contentName) {
		m_contentName = nullptr;
		if (width >= 5 && width <= 36 && length >= 5 && length <= 36 && height >= 5 && height <= 36)
		{
			m_width = width;
			m_height = height;
			m_length = length;
			m_contentVolume = 0;
			setName(contentName);
		}
		else
		{
			setUnusable();
		}
	}
	Box::~Box() {
		delete[] m_contentName;
		m_contentName = nullptr;
	}


	int Box::capacity()const {
		return m_width * m_height * m_length;
	}
	int Box::quantity()const {
		return m_contentVolume;
	}
	Box& Box::setContent(const char* contentName) {
		if (!hasContent() && !isUnusable())
		{
			setName(contentName);
		}
		return *this;
	}
	std::ostream& Box::display()const {
		if (isUnusable())
		{
			cout << "Unusable box, discard the content, and recycle.";
		}
		else
		{
			cout.width(30);
			cout.setf(ios::left);
			cout.fill('.');
			if (m_contentName == NULL)
			{
				cout << "Empty box";
			}
			else
			{
				cout << m_contentName;
			}
			cout << "  ";
			cout.unsetf(ios::left);

			cout.width(2);
			cout.setf(ios::right);
			cout.fill('0');
			cout << m_width;
			cout << 'x';
			cout.unsetf(ios::right);

			cout.width(2);
			cout.setf(ios::right);
			cout.fill('0');
			cout << m_height;
			cout << 'x';
			cout.unsetf(ios::right);

			cout.width(2);
			cout.setf(ios::right);
			cout.fill('0');
			cout << m_length;
			cout << "  ";
			cout.unsetf(ios::right);

			cout.width(6);
			cout.fill(' ');
			cout.setf(ios::right);
			cout << quantity();
			cout << '/';
			cout.unsetf(ios::right);

			cout << capacity() << " C.I.";
		}
		return cout;
	}
	Box& Box::add(int quantity) {

		if (quantity >= 0 && (quantity + this->quantity()) <= capacity())
		{
		m_contentVolume = quantity;
		}
		else
		{
			setUnusable();
		}
		
		return *this;
	}
	Box& Box::add(Box& B) {
		if (m_contentName == nullptr || quantity() == 0) {
			setContent(B.m_contentName);
		}
		if (strcmp(m_contentName, B.m_contentName) == 0) {
			if (quantity() + B.quantity() <= capacity()) {
				add(B.quantity());
				B.m_contentVolume = 0;
			}
			else {
				B.m_contentVolume -= (capacity() - quantity());
				m_contentVolume = capacity();
			}
		}
		else {
			if (quantity() + B.quantity() <= capacity()) {
				B.m_contentVolume = 0;
			}
			else {
				B.m_contentVolume -= (capacity() - quantity());
			}
			setUnusable();
		}
		return *this;
	}
}