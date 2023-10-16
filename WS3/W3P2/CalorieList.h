/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #3 (P2)
Full Name  : Bao Ngoc Ta
Student ID#: 116038225
Email      : bta@myseneca.ca
Date	   : 06/02/2023
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/


#pragma once
#ifndef SDDS_CALORIELIST_H_
#define SDDS_CALORIELIST_H_
#include "Food.h"

namespace sdds {
    class CalorieList {
        Food* m_items;
        int m_noOfItems;
        int m_itemsAdded;
        void Title()const;
        void footer()const;
        void setEmpty();
        bool isValid()const;
        int totalCal()const;
    public:
        void init(int size);
        bool add(const char* item_name, int calories, int when);
        void display()const;
        void deallocate();
    };
}


#endif // !SDDS_CALORIELIST_H_