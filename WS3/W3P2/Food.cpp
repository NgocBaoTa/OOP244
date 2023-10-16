/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #3 (P2)
Full Name  : Bao Ngoc Ta
Student ID#: 116038225
Email      : bta@myseneca.ca
Date	   : 06/02/2023
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/


#include <iostream>
#include "cstring.h"
#include "Food.h"
using namespace std;

namespace sdds {
	void Food::setEmpty() {
		m_calorie = 0;
		m_time = 0;
		m_name[0] = '\0';
	}

	void Food::set(const char* name, int cal, int time) {
		if (name == nullptr || cal < 0 || time < 0 || time > 3000) {
			setEmpty();
		}
		else {
			strnCpy(m_name, name, 30);
			m_name[30] = '\0';
			m_calorie = cal;
			m_time = time;
		}
	}

	bool Food::isValid() const {
		return (m_calorie > 0 && m_time > 0 && m_name[0] != '\0');
	}

	void Food::display()const {
		if (isValid()) {
			cout << "| ";
			cout.fill('.');
			cout.width(30);
			cout.setf(ios::left);
			cout << m_name;
			cout.unsetf(ios::left);
			cout.fill(' ');
			cout << " | ";
			cout.width(4);
			cout.setf(ios::fixed);
			cout << m_calorie;
			cout.unsetf(ios::fixed);
			cout << " | ";
			cout.width(10);
			cout.setf(ios::left);
			switch (m_time)
			{
			case 1:
				cout << "Breakfast" << " |" << endl;
				break;
			case 2: 
				cout << "Lunch" << " |" << endl;
				break;
			case 3: 
				cout << "Dinner" << " |" << endl;
				break;
			case 4: 
				cout << "Snack" << " |" << endl; 
				break;
			default:
				break;
			}
			cout.unsetf(ios::left);
		}
		else {
			cout << "| xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx | xxxx | xxxxxxxxxx |" << endl;
		}
	}
	int Food::calo() const
	{
		return m_calorie;
	}
}