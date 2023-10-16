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

#include <iostream>
#include "cstring.h"  
#include "Label.h"
using namespace std;

namespace sdds {
	Label::Label()
	{
		strCpy(frame, "+-+|+-+|");
		text = nullptr;
	}

	Label::Label(const char* frameArg)
	{
		strCpy(frame, frameArg);
		text = nullptr;
	}

	Label::Label(const char* frameArg, const char* content)
	{
		strCpy(frame, frameArg);
		int length = strLen(content);
		if (length <= 71) {
			text = new char[length + 1];
			strCpy(text, content);
		}
	}

	Label::~Label()
	{
		if (text) {
			delete[] text;
			text = nullptr;
		}
	}

	void Label::readLabel()
	{
		char content[71];
		if (text) {
			delete[] text;
			text = nullptr;
		}
		cout << "> ";
		cin.get(content, 71);
		cin.ignore(1000, '\n');
		text = new char[strLen(content) + 1];
		strCpy(text, content);
	}

	std::ostream& sdds::Label::printLabel() const
	{
		if (text) {
			int length = strLen(text);

			cout << frame[0];
			cout.fill(frame[1]);
			cout.width(length + 3);
			cout << frame[2] << endl;

			cout << frame[7];
			cout.fill(' ');
			cout.width(length + 3);
			cout << frame[3] << endl;

			cout << frame[7];
			cout << ' ' << text << ' ' << frame[3] << endl;

			cout << frame[7];
			cout.fill(' ');
			cout.width(length + 3);
			cout << frame[3] << endl;

			cout << frame[6];
			cout.fill(frame[5]);
			cout.width(length + 3);
			cout << frame[4];
		}
		return cout;
	}
}

