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
#include "Bill.h"
using namespace std;

namespace sdds {
	void Bill::setEmpty() {
		m_title[0] = '\0';                  
		m_items = nullptr;
	}

	bool Bill::isValid()const {
		if (m_title[0] == '\0' || m_items == nullptr) {
			return false;
		}

		for (int i = 0; i < m_noOfItems; i++) {      
			if (!m_items[i].isValid()) {
				return false;
			}
		}

		return true;
	}

	double Bill::totalTax()const {
		double sumTax = 0.0;
		for (int i = 0; i < m_itemsAdded; i++) {
			sumTax += m_items[i].tax();
		}
		return sumTax;
	}

	double Bill::totalPrice()const {
		double total = 0.0;
		for (int i = 0; i < m_itemsAdded; i++) {
			total += m_items[i].price();
		}
		return total;
	}

	void Bill::Title()const {
		cout << "+--------------------------------------+" << endl;
		if (isValid()) {
			cout << "| ";
			cout.setf(ios::left);
			cout.width(36);
			cout << m_title << " |" << endl;
			cout.unsetf(ios::left);
		}
		else {
			cout << "| Invalid Bill                         |" << endl;
		}

		cout << "+----------------------+---------+-----+" << endl <<
			    "| Item Name            | Price   + Tax |" << endl <<
			    "+----------------------+---------+-----+" << endl;
	}

	void Bill::footer()const {
		cout << "+----------------------+---------+-----+" << endl;
		if (isValid()) {
			cout << "|                Total Tax: ";
			cout.width(10);
			cout.precision(2);
			cout.setf(ios::fixed);
			cout << totalTax() << " |" << endl;
			cout << "|              Total Price: ";
			cout.width(10);
			cout << totalPrice() << " |" << endl;
			cout << "|          Total After Tax: ";
			cout.width(10);
			cout << totalPrice() + totalTax() << " |" << endl;
			cout.unsetf(ios::fixed);
		}
		else {
			cout << "| Invalid Bill                         |" << endl;
		}
		cout << "+--------------------------------------+" << endl;
	}

	void Bill::init(const char* title, int noOfItems) {
		if (title == nullptr || noOfItems <= 0) {                      
			setEmpty();
		}
		else {
			m_noOfItems = noOfItems;
			m_itemsAdded = 0;
			strnCpy(m_title, title, 36);
			m_title[36] = '\0';
			m_items = new Item[m_noOfItems];
			for (int i = 0; i < m_noOfItems; i++) {
				m_items[i].setEmpty();
			}
		}
	}

	bool Bill::add(const char* item_name, double price, bool taxed) {
		if (m_itemsAdded < m_noOfItems) {
			m_items[m_itemsAdded].set(item_name, price, taxed);
			m_itemsAdded++;
			return true;
		}
		else {
			return false;
		}
	}

	void Bill::display()const {
		Title();
		for (int i = 0; i < m_noOfItems; i++) {
			m_items[i].display();
		}
		footer();
	}

	void Bill::deallocate() {
		delete[] m_items;
		m_items = nullptr;
	}
}