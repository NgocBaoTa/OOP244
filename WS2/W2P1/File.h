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

#pragma once
#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds {
	bool openFile(const char filename[]);
	void closeFile();
	int noOfRecords();
	// TODO: Declare read prototypes
	
bool read(char name[]);
	bool read(int& m_Num);
	bool read(double& m_Salary);
}
#endif // !SDDS_FILE_H_