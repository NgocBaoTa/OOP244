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

#pragma once
#ifndef SDDS_MOTORVEHICLE_H__
#define SDDS_MOTORVEHICLE_H__
#include <iostream>
namespace sdds {
	class MotorVehicle {
		char m_licenseNum[9];
		char m_address[64];
		unsigned int m_year;
	public:
		MotorVehicle(const char* license, const unsigned int year);
		void moveTo(const char* address);
		std::ostream& write(std::ostream& os) const;
		std::istream& read(std::istream& in);
	};

	std::ostream& operator<<(std::ostream& os, const MotorVehicle& vehicle);
	std::istream& operator>>(std::istream& is, MotorVehicle& vehicle);
}
#endif