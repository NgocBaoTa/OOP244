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
#include "Truck.h"
using namespace std;

namespace sdds {
	Truck::Truck(const char* license, const unsigned int year, double capacity, const char* address)
		: MotorVehicle(license, year)
	{
		m_capacity = capacity;
		m_load = 0;
		moveTo(address);
	}

	bool Truck::addCargo(double cargo)
	{
		if (m_load != m_capacity) {
			if (m_load + cargo > m_capacity) {
				m_load = m_capacity;
			}
			else {
				m_load += cargo;
			}
			return true;
		}
		return false;
	}

	bool Truck::unloadCargo()
	{
		if (m_load != 0.0) {
			m_load = 0.0;
			return true;
		}
		return false;
	}

	istream& Truck::read(istream& in)
	{
			MotorVehicle::read(in);
			cout << "Capacity: ";
			in >> m_capacity;
			in.ignore(10000, '\n');
			cout << "Cargo: ";
			in >> m_load;
			in.ignore(10000, '\n');

			return in;
	}

	ostream& Truck::write(ostream& os) const
	{
		MotorVehicle::write(os);
		os << " | " << m_load << "/" << m_capacity;
		return os;
	}

	ostream& operator<<(ostream& os, const Truck& truck)
	{
		return truck.write(os);
	}

	istream& operator>>(istream& is, Truck& truck)
	{
		return truck.read(is);
	}

}