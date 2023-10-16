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
#ifndef _SDDS_CSTRING_H
#define _SDDS_CSTRING_H

namespace sdds {
	void strCpy(char* des, const char* src);
	void strnCpy(char* des, const char* src, int len);
	int strCmp(const char* s1, const char* s2);
	int strnCmp(const char* s1, const char* s2, int len);
	int strLen(const char* s);
	const char* strStr(const char* str1, const char* str2);
	void strCat(char* des, const char* src);

}
#endif // !_SDDS_CSTRING_H
