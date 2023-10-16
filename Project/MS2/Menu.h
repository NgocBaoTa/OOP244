// Final Project Milestone 2
// Menu Module
// File	Menu.h
// Version 1.0
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name: Bao Ngoc Ta               
// Date: 07/19/2023              
// Authenticity Declaration :
// I have done all the coding by myself and only copied the code that my
// professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////

#pragma once
#ifndef SDDS_MENU_H__
#define SDDS_MENU_H__
#include <iostream>

namespace sdds {
    const int MAX_MENU_ITEMS = 20;

    class MenuItem {
        char* m_content{ nullptr };
        MenuItem(const char* content);
        ~MenuItem();
        operator bool();
        operator const char* () const;
        void display(std::ostream& os) const;
        friend class Menu;
        MenuItem(const MenuItem&) = delete;
        MenuItem& operator=(const MenuItem&) = delete;
    };

    class Menu {
        char* m_title{ nullptr };
        MenuItem* m_menuItems[MAX_MENU_ITEMS]{ nullptr };
        unsigned m_noOfItems;
    public:
        Menu();
        Menu(const char* title);
        ~Menu();
        void displayTitle(std::ostream& os) const;
        void displayMenu(std::ostream& os) const;
        unsigned int run() const;
        unsigned int operator~() const;
        Menu& operator<<(const char* menuitemConent);
        operator int() const;
        operator unsigned int() const;
        operator bool() const;
        const char* operator[](int index) const;
        Menu(const Menu&) = delete;
        Menu& operator=(const Menu&) = delete;
        friend std::ostream& operator<<(std::ostream& os, const Menu& menu);
    };
}
#endif