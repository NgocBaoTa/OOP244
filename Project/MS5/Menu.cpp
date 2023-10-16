// Final Project Milestone 2 
// Menu Module
// File	Menu.cpp
// Version 1.0
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name: Bao Ngoc Ta               
// Date: 07/29/2023              
// Authenticity Declaration :
// I have done all the coding by myself and only copied the code that my
// professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <ctime>
#include <cstring>
#include "Menu.h"
using namespace std;
namespace sdds {
	MenuItem::MenuItem(const char* content = NULL)
	{
		if (content) {
			m_content = new char[strlen(content) + 1];
			strcpy(m_content, content);
		}
		else {
			m_content = nullptr;
		}
	}

	MenuItem::~MenuItem()
	{
		delete[] m_content;
		m_content = nullptr;
	}

	MenuItem::operator bool()
	{
		if (m_content) {
			return true;
		}
		return false;
	}

	MenuItem::operator const char* () const
	{
		return &m_content[0];
	}

	void MenuItem::display(std::ostream& os) const
	{
		if (m_content) {
			os << m_content;
		}
	}

	//============================ MENU =================================

	Menu::Menu()
	{
		m_title = nullptr;
		m_noOfItems = 0;
		for (unsigned int i = 0; i < MAX_MENU_ITEMS; ++i) {
			m_menuItems[i] = nullptr;
		}
	}

	Menu::Menu(const char* title)
	{
		if (title) {

			m_title = new char[strlen(title) + 1];
			strcpy(m_title, title);
		}
		m_noOfItems = 0;
		for (unsigned int i = 0; i < MAX_MENU_ITEMS; ++i) {
			m_menuItems[i] = nullptr;
		}
	}

	Menu::~Menu()
	{
		if (m_menuItems) {
			for (unsigned int i = 0; i < m_noOfItems; ++i) {
				delete m_menuItems[i];
				m_menuItems[i] = nullptr;
			}
		}

		delete[] m_title;
		m_title = nullptr;
		m_noOfItems = 0;
	}

	void Menu::displayTitle(std::ostream& os) const
	{
		if (m_title) {
			os << m_title << "\n";
		}
	}

	void Menu::displayMenu(std::ostream& os) const
	{
		displayTitle(os);
		for (unsigned int i = 0; i < m_noOfItems; i++) {
			os << " " << i + 1 << "- ";
			m_menuItems[i]->display(os);
			os << "\n";
		}
		os << " 0- Exit\n";
		os << "> ";
	}


	unsigned int Menu::run() const
	{
		unsigned int selection;
		displayMenu(cout);

		bool validSelection = false;
		while (!validSelection) {
			cin >> selection;

			if (!cin || selection < 0 || selection > m_noOfItems) {
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Invalid Selection, try again: ";
				validSelection = false;
			}
			else {
				validSelection = true;
			}
		}

		return selection;
	}

	unsigned int Menu::operator~() const
	{
		return run();
	}

	Menu& Menu::operator<<(const char* menuitemContent) {
		if (m_noOfItems < MAX_MENU_ITEMS) {
			MenuItem* item = new MenuItem(menuitemContent);
			m_menuItems[m_noOfItems] = item;
			++m_noOfItems;
		}
		return *this;
	}

	Menu::operator int() const
	{
		return m_noOfItems;
	}

	const char* Menu::operator[](int index) const
	{
		if (m_noOfItems > 0) {
			int adjustedIndex = index % m_noOfItems;
			return m_menuItems[adjustedIndex]->operator const char* ();

		}
		return nullptr;
	}

	Menu::operator unsigned int() const
	{
		return m_noOfItems;
	}

	Menu::operator bool() const
	{
		return m_noOfItems > 0;
	}

	std::ostream& operator<<(std::ostream& os, const Menu& menu)
	{
		if (menu.m_title) {
			os << menu.m_title;
		}
		return os;
	}
}


