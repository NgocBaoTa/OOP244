/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #7 (P1)
Full Name  : Bao Ngoc Ta
Student ID#: 116038225
Email      : bta@myseneca.ca
Date	   : 10/07/2023
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/


#include <iostream>
#include "cstring.h"
using namespace std;

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


	void strnCpy(char* des, const char* src, int len) {
		int i = 0;
		while (i < len - 1 && src[i]) {
			des[i] = src[i];
			i++;
		}
		des[i] = src[i];
	}

	int strCmp(const char* s1, const char* s2) {

		int i = 0;
		while (s1[i] && s2[i] && s1[i] == s2[i]) {
			i++;
		}
		return s1[i] - s2[i];
	}

	int strnCmp(const char* s1, const char* s2, int len) {
		int i = 0;
		while (i < len && s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]) {
			i++;
		}

		if (i == len) {
			return 0;
		}
		else if (s1[i] > s2[i]) {
			return 1;
		}
		else {
			return -1;
		}
	}

	int strLen(const char* s) {

		int i = -1;
		while (s[++i]);
		return i;
	}

	const char* strStr(const char* str1, const char* str2) {
		if (*str2 == '\0') {
			return str1;
		}

		int i = 0;
		while (str1[i] != '\0') {
			int flag = 0, j;
			int k = i;
			for (j = 0; str2[j] != '\0' && flag == 0; j++) {
				if (str1[k] != str2[j]) {
					flag = 1;
				}
				else {
					k++;
				}
			}

			if (flag == 0) {
				return &str1[i];
			}
			i++;
		}

		return nullptr;
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

