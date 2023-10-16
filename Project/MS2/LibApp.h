// Final Project Milestone 2
// LibApp Module
// File	LibApp.h
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
#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H
#include "Menu.h"

namespace sdds {
	class LibApp {
		bool m_changed;
		Menu m_mainMenu;
		Menu m_exitMenu;
		void load();  
		void save();  
		void search(); 
		void returnPub();  
		bool confirm(const char* message);
		void newPublication();
		void removePublication();
		void checkOutPub();

	public: 
		LibApp();
		void run();
	};
}
#endif // !SDDS_LIBAPP_H