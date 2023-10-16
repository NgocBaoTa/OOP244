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
#ifndef SDDS_FOOD_H_
#define SDDS_FOOD_H_

namespace sdds {
	class Food {
		char m_name[31];
		int m_calorie;
		int m_time;
	public:
		void set(const char* name, int cal, int time);
		void setEmpty();
		bool isValid() const;
		void display() const;
		int calo() const;
	};
}

#endif // !SDDS_FOOD_H_

