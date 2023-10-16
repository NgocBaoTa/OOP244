#include <iostream>
#include "Utils.h"
using namespace std;
namespace sdds {
    int getIntegerInput(int minRange, int maxRange) {
        int input;
        bool validInt;

        do {

            cin >> input;

            if (cin.fail() || input < minRange || input > maxRange) {
                cout << "Invalid selection, try again: ";
                cin.clear();
                cin.ignore(1000, '\n');
                validInt = false;
            }
            else {
                validInt = true;
            }
        } while (!validInt);

        return input;
    }
	void strCpy(char* des, const char* src) {
		int i = 0;
		for (i = 0; src[i] != '\0'; i++) {
			des[i] = src[i];
		}
		des[i] = '\0';
	}
	void strnCpy(char* des, const char* src, int len) {
		int i;
		for (i = 0; i < len; i++) {
			des[i] = src[i];
		}
	}
	int strCmp(const char* s1, const char* s2) {
		int i;
		int flag = 0;
		for (i = 0; s1[i] != '\0' && s2[i] != '\0' && flag == 0; i++) {
			if (s1[i] != s2[i]) {
				if (s1[i] > s2[i]) {
					flag = 1;
				}
				else {
					flag = -1;
				}

			}
		}
		return flag;
	}
	int strnCmp(const char* s1, const char* s2, int len) {
		int i;
		int flag = 0;
		for (i = 0; i < len && flag == 0; i++) {
			if (s1[i] != s2[i]) {
				if (s1[i] > s2[i]) {
					flag = 1;
				}
				else {
					flag = -1;
				}
			}
		}
		return flag;
	}
	int strLen(const char* s) {
		int i;
		int count = 0;
		for (i = 0; s[i] != '\0'; i++) {
			count++;
		}
		return count;
	}

	const char* strStr(const char* str1, const char* str2) {

		while (*str1) {
			const char* p1 = str1;
			const char* p2 = str2;

			while (*p1 && *p2 && *p1 == *p2) {
				p1++;
				p2++;
			}

			if (*p2 == '\0') {
				return str1;
			}

			str1++;
		}

		return nullptr;

	}
	/*const char* strStr(const char* str, const char* find) {
		const char* faddress = nullptr;
		int i, flen = strLen(find), slen = strLen(str);
		for (i = 0; i < slen - flen && strnCmp(&str[i], find, flen); i++);
		if (i < slen - flen) faddress = &str[i];
		return faddress;
	}*/




	void strCat(char* des, const char* src) {

		strCpy(des + strLen(des), src);
	}

}