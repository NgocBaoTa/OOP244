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
#include "CalorieList.h"
using namespace std;

namespace sdds {
	void CalorieList::Title() const
	{
		cout << "+----------------------------------------------------+" << endl;

		if (isValid()) {
			cout << "|  Daily Calorie Consumption                         |" << endl;
		}
		else {
			cout << "| Invalid Calorie Consumption list                   |" << endl;
		}

		cout << "+--------------------------------+------+------------+" << endl <<
			"| Food name                      | Cals | When       |" << endl <<
			"+--------------------------------+------+------------+" << endl;
	}

	void CalorieList::footer() const
	{
		cout << "+--------------------------------+------+------------+" << endl;

		if (isValid()) {
			cout << "|    Total Calories for today:";
			cout.width(9);
			cout.setf(ios::fixed);
			cout << totalCal() << " |            |" << endl;
			cout.unsetf(ios::fixed);
		}
		else {
			cout << "|    Invalid Calorie Consumption list                |" << endl;
		}
		cout << "+----------------------------------------------------+" << endl;

	}

	void CalorieList::setEmpty()
	{
		m_items = nullptr;
		m_itemsAdded = 0;
		m_noOfItems = 0;
	}

	bool CalorieList::isValid() const
	{
		if (m_items == nullptr) {
			return false;
		}
		else {
			for (int i = 0; i < m_noOfItems; i++) {
				if (!m_items[i].isValid()) {
					return false;
				}
			}
		}
		
		return true;
	}

	int CalorieList::totalCal() const
	{
		int total = 0;
		for (int i = 0; i < m_noOfItems; i++) {
			total += m_items[i].calo();
		}

		return total;
	}

	void CalorieList::init(int size)
	{
		if (size <= 0) {
			setEmpty();
		}
		else {
			m_noOfItems = size;
			m_itemsAdded = 0;
			m_items = new Food[m_noOfItems];
			for (int i = 0; i < m_noOfItems; i++) {
				m_items[i].setEmpty();
			}
		}
	}

	bool CalorieList::add(const char* item_name, int calories, int when)
	{
		if (m_itemsAdded < m_noOfItems) {
			m_items[m_itemsAdded].set(item_name, calories, when);
			m_itemsAdded++;
			return true;
		}
		else {
			return false;
		}
	}

	void CalorieList::display() const
	{
		Title();
		for (int i = 0; i < m_noOfItems; i++) {
			m_items[i].display();
		}
		footer();
	}

	void CalorieList::deallocate()
	{
		delete[] m_items;
		m_items = nullptr;
	}
}
