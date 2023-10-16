/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #3 (P1)
Full Name  : Bao Ngoc Ta
Student ID#: 116038225
Email      : bta@myseneca.ca
Date	   : 05/31/2023
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#include <iostream>
#include "cstring.h"
#include "Item.h"
using namespace std;

namespace sdds {
	void Item::setName(const char* name) {
		strnCpy(m_itemName, name, 20);
		m_itemName[20] = '\0';
	}

	void Item::setEmpty() {
		m_price = 0.0;
		m_itemName[0] = '\0';                        
	}

	void Item::set(const char* name, double price, bool taxed) {
		if (name == nullptr || price < 0.0) {          
			setEmpty();
		}
		else {
			setName(name);
			m_price = price;
			m_taxed = taxed;
		}
	}

	double Item::price()const {
		return m_price;
	}

	double Item::tax()const {
		const double taxRate = 0.13;
		return (m_taxed ? m_price * taxRate : 0.0);
	}

	bool Item::isValid()const {
		return (m_price != 0.0 && m_itemName[0] != '\0');     
	}

	void Item::display()const {
		if (isValid()) {
			cout << "| ";
			cout.fill('.');
			cout.width(20);
			cout.setf(ios::left);
			cout << m_itemName;
			cout.unsetf(ios::left);
			cout.fill(' ');
			cout << " | ";
			cout.width(7);
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << m_price;
			cout.unsetf(ios::fixed);
			cout << " | ";
			cout << (m_taxed ? "Yes" : "No ") << " |" << endl;
		}
		else {
			cout << "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |" << endl;
		}
	}
}