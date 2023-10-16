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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Label.h"
#include "cstring.h"  
#include "LabelMaker.h"
using namespace std;

namespace sdds {
	LabelMaker::LabelMaker(int noOfLabels)
	{
		totalOfLabel = noOfLabels;
		listLabel = new Label[totalOfLabel];
	}

	LabelMaker::~LabelMaker()
	{
		delete[] listLabel;
		listLabel = nullptr;
	}

	void LabelMaker::readLabels()
	{
		if (totalOfLabel > 0) {
			cout << "Enter " << totalOfLabel << " labels:" << endl;
			for (int i = 0; i < totalOfLabel; i++) {
				cout << "Enter label number " << i + 1 << endl;
				listLabel[i].readLabel();
			}
		}
	}

	void LabelMaker::printLabels()
	{
		for (int i = 0; i < totalOfLabel; i++) {
			listLabel[i].printLabel();
			cout << endl;
		}
	}
}
