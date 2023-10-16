// Final Project Milestone 1 
// Book Module
// File	Book.cpp
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
using namespace std;
#include "Date.h"
#include "Book.h"
namespace sdds {
    Book::Book() : Publication()
    {
        m_author = nullptr;
    }

    Book::Book(const Book& book) : Publication(book)
    {
        *this = book;
    }

    Book::~Book()
    {
        if (m_author) {
            delete[] m_author;
            m_author = nullptr;
        }
    }

    Book& Book::operator=(const Book& book)
    {
        Publication::operator=(book);
        if (this != &book) {
            if (m_author) {
                delete[] m_author;
                m_author = nullptr;
            }

            if (book.m_author) {
                m_author = new char[strlen(book.m_author) + 1];
                strcpy(m_author, book.m_author);
            }
        }
        return *this;
    }

    void Book::set(int member_id)
    {
        Publication::set(member_id);
        Publication::resetDate();
    }

    char Book::type() const
    {
        return 'B';
    }

    ostream& Book::write(ostream& os) const
    {
        Publication::write(os);
        if (conIO(os)) {
            char author[SDDS_AUTHOR_WIDTH + 1] = { 0 };
            strncpy(author, m_author, SDDS_AUTHOR_WIDTH);
            os << " " << setw(SDDS_AUTHOR_WIDTH) << left << author << " |";
        }
        else {
            os << "\t" << m_author;
        }

        return os;
    }

    istream& Book::read(istream& istr)
    {
        char author[256] = { 0 };
        Publication::read(istr);
        if (m_author) {
            delete[] m_author;
            m_author = nullptr;
        }

        if (conIO(istr)) {
            istr.ignore();
            cout << "Author: ";
            istr.get(author, 256);
        }
        else {
            istr.ignore(1000, '\t');
            istr.get(author, 256);
        }

        if (istr) {
            m_author = new char[strlen(author) + 1];
            strcpy(m_author, author);
        }

        return istr;
    }

    Book::operator bool() const
    {
        return m_author && Publication::operator bool();
    }

}

