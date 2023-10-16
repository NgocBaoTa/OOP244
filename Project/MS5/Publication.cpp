// Final Project Milestone 1 
// Publication Module
// File	Publication.cpp
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
#include <cstring>
#include <iostream>
#include <ctime>
#include "Date.h"
#include "Publication.h"
#include "Lib.h"
using namespace std;
namespace sdds {
	Publication::Publication()
	{
		m_title = nullptr;
		m_shelfId[0] = '\0';
		m_membership = 0;
		m_libRef = -1;
		m_date.setToToday();
	}

	// Sets the membership attribute to either zero or a five-digit integer.
	void Publication::set(int member_id)
	{
		m_membership = member_id;

	}

	Publication::~Publication() {
		delete[] m_title;
	}

	Publication::Publication(const Publication& publication)
	{
		*this = publication;
	}

	Publication& Publication::operator=(const Publication& publication)
	{
		set(publication.m_membership);
		setRef(publication.m_libRef);
		strcpy(m_shelfId, publication.m_shelfId);
		m_date = publication.m_date;

		if (m_title)
		{
			delete[] m_title;
			m_title = nullptr;
		}

		// Deep Copying
		if (publication.m_title != nullptr) {
			m_title = new char[strlen(publication.m_title) + 1];
			strcpy(m_title, publication.m_title);
		}
		else {
			m_title = nullptr;
		}

		return *this;
	}

	// Sets the **libRef** attribute value
	void Publication::setRef(int value)
	{
		m_libRef = value;
	}

	// Sets the date to the current date of the system.
	void Publication::resetDate()
	{
		m_date = Date();
	}

	//Returns the character 'P' to identify this object as a "Publication object"
	char Publication::type() const
	{
		return 'P';
	}

	//Returns true is the publication is checkout (membership is non-zero)
	bool Publication::onLoan() const
	{
		return m_membership != 0;
	}

	//Returns the date attribute
	Date Publication::checkoutDate() const
	{
		return m_date;
	}

	//Returns true if the argument title appears anywhere in the title of the 
	//publication. Otherwise, it returns false; (use strstr() function in <cstring>)
	bool Publication::operator==(const char* title) const
	{
		return strstr(m_title, title) != nullptr;
	}

	//Returns the title attribute
	Publication::operator const char* () const
	{
		return m_title;
	}

	//Returns the libRef attirbute. 
	int Publication::getRef() const
	{
		return m_libRef;
	}

	bool Publication::conIO(ios& io) const {
		return &io == &cin || &io == &cout;
	}

	ostream& Publication::write(ostream& os) const
	{
		char title[SDDS_TITLE_WIDTH + 1] = { 0 };
		strncpy(title, m_title, SDDS_TITLE_WIDTH);
		if (conIO(os)) {
			os << "| "  << m_shelfId << " | "
				<< left << setw(SDDS_TITLE_WIDTH) << setfill('.') << title << " | ";
			if (m_membership == 0)
				os << " N/A ";
			else {
				os  << m_membership;
			}
			os << " | " << m_date << " |";
		}
		else {
			os << type() << "\t" << m_libRef << "\t" << m_shelfId << "\t" << m_title << "\t";
			
				os << m_membership;
			
			os << "\t" << m_date;
		}

		return os;
	}

	istream& Publication::read(istream& istr)
	{
		if (m_title) {
			delete[] m_title;
			m_title = nullptr;
		}
		m_shelfId[0] = '\0';
		m_membership = 0;
		resetDate();
		m_libRef = -1;

		char shelfId[SDDS_SHELF_ID_LEN + 1]{};
		char title[256]{};
		int membership = 0;
		Date date;
		int libRef = -1;

		if (conIO(istr)) {
			cout << "Shelf No: ";
			istr.getline(shelfId, SDDS_SHELF_ID_LEN + 1);
			if (strlen(shelfId) != SDDS_SHELF_ID_LEN) {
				istr.setstate(ios::failbit);
			}

			cout << "Title: ";
			istr.getline(title, 256);
			cout << "Date: ";
			istr >> date;

		}
		else {
			istr >> libRef;
			istr.ignore();
			istr.getline(shelfId, SDDS_SHELF_ID_LEN + 1, '\t');
			istr.getline(title, 256, '\t');
			istr >> membership;
			istr.ignore();
			istr >> date;
		}
		if (!date) {
			istr.setstate(ios::failbit);
		}
		if (istr) {
			strcpy(m_shelfId, shelfId);
			m_title = new char[strlen(title) + 1];
			strcpy(m_title, title);
			m_membership = membership;
			m_libRef = libRef;
			m_date = date;
		}

		return istr;
	}

	Publication::operator bool() const
	{
		return m_title != nullptr && m_shelfId[0] != '\0';
	}
}





