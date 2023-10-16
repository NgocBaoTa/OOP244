// Final Project Milestone 1 
// Book Module
// File	Book.h
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
#ifndef SDDS_BOOK_H__
#define SDDS_BOOK_H__
#include <iostream>
#include "Publication.h"
#include "Lib.h"
using namespace std;
namespace sdds {
	class Book : public Publication {
		char* m_author{ nullptr };
	public:
		Book();
		Book(const Book& book);
		~Book();
		Book& operator=(const Book& book);
		void set(int member_id) override;
		char type()const override;
		ostream& write(ostream& os) const override;
		istream& read(istream& istr) override;
		operator bool() const override;
	};
}
#endif