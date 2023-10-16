/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #6 (P1)
Full Name  : Bao Ngoc Ta
Student ID#: 116038225
Email      : bta@myseneca.ca
Date	   : 07/07/2023
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#include "cstring.h"
#include <iostream>
namespace sdds {
	void strCpy(char* des, const char* src) {
		int i = 0;
		if (des != NULL && src != NULL) {
			while (src[i] != '\0') {
				des[i] = src[i];
				i++;
			}
			des[i] = '\0';
		}
	}

	int strLen(const char* s) {

		int i = -1;
		while (s[++i]);
		return i;
	}

	void strCat(char* des, const char* src) {
		if (des != NULL && src != NULL)
		{
			int len = strLen(des), i;
			{
				for (i = 0; src[i] != '\0'; i++)
				{
					des[len++] = src[i];
				}
				des[len] = '\0';
			}
		}
	}
}