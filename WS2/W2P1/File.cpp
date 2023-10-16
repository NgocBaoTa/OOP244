/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P1)
Full Name  : Bao Ngoc Ta
Student ID#: 116038225
Email      : bta@myseneca.ca
Date	   : 05/24/2023
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace sdds {
    FILE* fptr;
    bool openFile(const char filename[]) {
        fptr = fopen(filename, "r");
        return fptr != NULL;
    }
    int noOfRecords() {
        int noOfRecs = 0;
        char ch;
        while (fscanf(fptr, "%c", &ch) == 1) {
            noOfRecs += (ch == '\n');
        }
        rewind(fptr);
        return noOfRecs;
    }
    void closeFile() {
        if (fptr) fclose(fptr);
    }


    /* TODO: read functions go here
    bool read(................) {
       return .....
    }
    bool read(................) {
       return .....
    }
    bool read(................) {
       return .....
    }
    */


    bool read(char name[]) {
        return fscanf(fptr, "%[^\n]\n", name) == 1;
    }
    bool read(int& m_Num) {
        return fscanf(fptr, "%d,", &m_Num) == 1;
    }
    bool read(double& m_Salary) {
        return fscanf(fptr, "%lf,", &m_Salary) == 1;
    }
}