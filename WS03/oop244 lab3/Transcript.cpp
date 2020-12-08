//name:Yuelin Wen yewn26@myseneca.ca
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include<cstdio>
#include "Transcript.h"
using namespace std;
namespace sdds {
	void Transcript::setEmpty() {
		m_studentName = nullptr;
		m_subjects = nullptr;
	}
	bool Transcript::isValid()const {
		bool valid = false;
		if (m_studentName != nullptr && m_subjects != nullptr)
		{
			valid = true;
			for (int i = 0; valid && i < m_noOfSubjects; i++) {
				valid = m_subjects[i].isValid();
			}
		}
		return valid;
	}
	void Transcript::Title()const {
		cout << m_studentName << endl
			<< "-----------------------------" << endl;
	}
	float Transcript::gpa()const {
		float gpa = 0;
		for (int i = 0; i < m_noOfSubjects; i++)
		{
			gpa = m_subjects[i].scale4() + gpa;
		}
		gpa = gpa / m_noOfSubjects;
		return gpa;
	}
	void Transcript::footer()const {
		cout << "-----------------------------" << endl
			<< "                     " << "GPA: ";
		cout.setf(ios::fixed);
		cout.precision(1);
		cout << gpa() << endl;
	}

	void Transcript::init(const char* studentName, int noOfSubjects) {
		if (studentName[0] != '\0' || noOfSubjects >= 0)
		{
			m_noOfSubjects = noOfSubjects;
			m_subjectsAdded = 0;
			m_studentName = new char[strlen(studentName) + 1];
			strcpy(m_studentName, studentName);
			m_subjects = new Subject[m_noOfSubjects];
			for (int i = 0; i < m_noOfSubjects; i++)
			{
				m_subjects[i].setEmpty();
			}
		}
		else
		{
			setEmpty();
		}
	}
	bool Transcript::add(const char* subject_code, int mark) {
		bool add = true;
		if (m_subjectsAdded < m_noOfSubjects)
		{
			m_subjects[m_subjectsAdded].set(subject_code, mark);
			m_subjectsAdded++;
		}
		else
		{
			add = false;
		}
		return add;
	}
	void Transcript::display()const {
		if (isValid())
		{
			Title();
			for (int i = 0; i < m_subjectsAdded; i++)
			{
				m_subjects[i].display();
			}
			footer();
		}
		else
		{
			cout << "Invalid Transcript!" << endl;
		}
	}
	void Transcript::deallocate() {
		delete[] m_studentName;
		delete[] m_subjects;
		m_studentName = nullptr;
		m_subjects = nullptr;
	}
}