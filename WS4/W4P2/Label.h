/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #4 (P2)
Full Name  : Bao Ngoc Ta
Student ID#: 116038225
Email      : bta@myseneca.ca
Date	   : 06/09/2023
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#pragma once
#include <ostream>
#ifndef SDDS_LABEL_H
#define SDDS_LABEL_H

namespace sdds {
	class Label {
		char frame[9];
		char* text;
	public:
		Label();
		Label(const char* frameArg);
		Label(const char* frameArg, const char* content);
		~Label();
		void readLabel();
		std::ostream& printLabel()const;
	};
}

#endif // !SDDS_LABEL_H
