/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #3 (P1)
Full Name  : Bao Ngoc Ta
Student ID#: 116038225
Email      : bta@myseneca.ca
Date	   : 05/31/2023
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#pragma once
#ifndef SDDS_ITEM_H_
#define SDDS_ITEM_H_
namespace sdds {
	class Item {
		char m_itemName[21];
		double m_price;
		bool m_taxed;
		void setName(const char* name);
	public:
		void setEmpty();
		void set(const char* name, double price, bool taxed);
		void display()const;
		bool isValid()const;
		double price()const;
		double tax()const;
	};
}

#endif // !SDDS_SUBJECT_H
