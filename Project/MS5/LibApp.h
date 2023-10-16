// Final Project Milestone 2
// LibApp Module
// File	LibApp.h
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

#pragma once
#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H
#include "Menu.h"
#include "Publication.h"
#include "Lib.h"

namespace sdds {
	class LibApp {
		bool m_changed;
		Menu m_mainMenu;
		Menu m_exitMenu;

		char m_filename[256]{};
		Publication* m_PPA[SDDS_LIBRARY_CAPACITY];           //Publication Pointers Array
		int m_NOLP;                                          //Number Of Loaded Publications
		int m_LLRN;                                          //Last Library Reference Number
		Menu m_typeMenu;

		void load();
		void save();
		int search(int searchType);
		void returnPub();
		bool confirm(const char* message);
		void newPublication();
		void removePublication();
		void checkOutPub();

	public:
		LibApp(const char* fileName);
		~LibApp();
		void run();
		Publication* getPub(int libRef);
	};
}
#endif // !SDDS_LIBAPP_H