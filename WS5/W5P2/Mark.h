/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #5 (P2)
Full Name  : Bao Ngoc Ta
Student ID#: 116038225
Email      : bta@myseneca.ca
Date	   : 06/13/2023
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#pragma once
#ifndef SDDS_MARK_H
#define SDDS_MARK_H

namespace sdds {
	class Mark {
		int m_mark;
		void setEmpty();
	public: 
		Mark();
		Mark(const int value);
		operator int() const;
		operator double() const; 
		operator char() const;
		bool operator!() const;
		Mark& operator+=(const int value);
		Mark& operator=(const int value);
	};
	
	int operator+=(int& value, const Mark _mark);
}

#endif // !SDDS_MARK_H
