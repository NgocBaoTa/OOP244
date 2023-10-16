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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "MotorVehicle.h"
#include "cstring.h"
using namespace std;
namespace sdds {
	MotorVehicle::MotorVehicle(const char* license, const unsigned int year)
	{
		strnCpy(m_address, "Factory", 64);
		m_address[63] = '\0';
		strnCpy(m_licenseNum, license, 8);
		m_licenseNum[8] = '\0';
		m_year = year;
	}

	void MotorVehicle::moveTo(const char* address)
	{
		if (strCmp(m_address, address)) {
			cout << "|";
			cout.width(8);
			cout << m_licenseNum;
			cout << "| |";
			cout.width(20);
			cout << m_address;
			cout << " ---> ";
			cout.width(20);
			cout.setf(ios::left);
			cout << address;
			cout.unsetf(ios::left);
			cout << "|\n";
			strnCpy(m_address, address, 63);
			m_address[63] = '\0';
		}
	}

	ostream& MotorVehicle::write(ostream& os) const
	{
		os << "| ";
		os << m_year; 
		os << " | ";
		os << m_licenseNum;
		os << " | ";
		os << m_address;
		return os;
	}

	istream& MotorVehicle::read(istream& in)
	{
		cout << "Built year: ";
		in >> m_year;
		in.ignore(10000, '\n');
		cout << "License plate: ";
		in.getline(m_licenseNum, 9);
		cout << "Current location: ";
		in.getline(m_address, 64);

		return in;
	}

	std::ostream& operator<<(std::ostream& os, const MotorVehicle& vehicle)
	{
		return vehicle.write(os);
	}

	std::istream& operator>>(std::istream& is, MotorVehicle& vehicle)
	{
		return vehicle.read(is);
	}

}