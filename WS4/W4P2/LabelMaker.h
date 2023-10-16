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
#ifndef SDDS_LABELMAKER_H
#define SDDS_LABELMAKER_H

namespace sdds {
	class LabelMaker {
		Label* listLabel;
		int totalOfLabel;
	public:
		LabelMaker(int noOfLabels);
		~LabelMaker();
		void readLabels();
		void printLabels();
	};
}

#endif // !SDDS_LABELMAKER_H
