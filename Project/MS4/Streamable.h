// Final Project Milestone 1 
// Streamable Module
// File	Streamable.cpp
// Version 1.0
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name: Bao Ngoc Ta               
// Date: 07/27/2023              
// Authenticity Declaration :
// I have done all the coding by myself and only copied the code that my
// professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////

#pragma once
#ifndef SDDS_STREAMABLE_H__
#define SDDS_STREAMABLE_H__
#include <iostream>
using namespace std;
namespace sdds {
	class Streamable {
	public:
		virtual ostream& write(ostream& os) const = 0;
		virtual istream& read(istream& is) = 0;
		virtual bool conIO(ios& io) const = 0;
		virtual operator bool() const = 0;
		virtual ~Streamable() = default;
		friend ostream& operator<<(ostream& os, const Streamable& S) {
			if (bool(S)) {
				S.write(os);
			}return os;
		}


		friend istream& operator>>(istream& is, Streamable& S) {
			S.read(is);
			return is;
		}
	};
}
#endif