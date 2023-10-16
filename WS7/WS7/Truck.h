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
#ifndef SDDS_TRUCK_H__
#define SDDS_TRUCK_H__
#include "MotorVehicle.h"
#include <iostream>
using namespace std;

namespace sdds {
	class Truck : public MotorVehicle {
		double m_capacity;
		double m_load;
	public:
		Truck(const char* license, const unsigned int year, double capacity, const char* address);
		bool addCargo(double cargo);
		bool unloadCargo();
		istream& read(istream& in);
		ostream& write(ostream& os) const;
	};

	ostream& operator<<(ostream& os, const Truck& truck);
	istream& operator>>(istream& is, Truck& truck);
}
#endif
