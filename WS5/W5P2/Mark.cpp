/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #5 (P2)
Full Name  : Bao Ngoc Ta
Student ID#: 116038225
Email      : bta@myseneca.ca
Date	   : 06/13/2023
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#include "Mark.h"
using namespace std;

namespace sdds {
	void Mark::setEmpty()
	{
		m_mark = -1; 
	}

	bool Mark::operator!() const
	{
		return (m_mark >= 0 && m_mark <= 100);
	}

	Mark::Mark()
	{
		m_mark = 0;
	}

	Mark::Mark(const int value)
	{
		if (value >= 0 && value <= 100) {
			m_mark = value;
		}
		else {
			setEmpty();
		}
	}

	Mark::operator int() const
	{
		if (!*this) {
			return m_mark;
		}
		else {
			return 0;
		}
	}

	Mark::operator double() const
	{
		double gpa = 0.0;
		if (m_mark >= 50 && m_mark < 60) {
			gpa = 1.0;
		} else if (m_mark >= 60 && m_mark < 70) {
			gpa = 2.0;
		} else if(m_mark >= 70 && m_mark < 80) {
			gpa = 3.0;
		} else if (m_mark >= 80 && m_mark <= 100) {
			gpa = 4.0;
		}
		return gpa;
	}

	Mark::operator char() const
	{
		char result = 'X';
		if (m_mark >= 0 && m_mark < 50) {
			result = 'F';
		}
		else if (m_mark >= 50 && m_mark < 60) {
			result = 'D';
		}
		else if (m_mark >= 60 && m_mark < 70) {
			result = 'C';
		}
		else if (m_mark >= 70 && m_mark < 80) {
			result = 'B';
		}
		else if (m_mark >= 80 && m_mark <= 100) {
			result = 'A';
		}
		return result;
	}

	Mark& Mark::operator+=(const int value)
	{
		if (!*this) {
			if (value >= 0 && value <= 100) {
				m_mark += value; 
			}
 		}

		return *this;
	}

	Mark& Mark::operator=(const int value)
	{
		m_mark = value;

		return *this;
	}

	int operator+=(int& value, const Mark _mark)
	{
		int mark = (int)_mark;
		if (mark >= 0 && mark <= 100) {
			value += mark;
		}
		return value;
	}
}