/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #4 (P1)
Full Name  : Bao Ngoc Ta
Student ID#: 116038225
Email      : bta@myseneca.ca
Date	   : 06/03/2023
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#include <istream>
#include <iomanip>
#include "cstring.h"  // using strLen, strCpy and strCmp 
#include "Canister.h"
using namespace std;


namespace sdds {
	const double PI = 3.14159265;
	void Canister::setToDefault()
	{
		m_contentName = nullptr;
		m_height = 13.0;
		m_diameter = 10.0;
		m_contentVolume = 0.0;
		m_usable = true;
	}

	void Canister::setName(const char* Cstr)
	{
		if (Cstr && m_usable) {
			delete[] m_contentName;
			m_contentName = new char[strLen(Cstr) + 1];
			strCpy(m_contentName, Cstr);
		}
	}

	bool Canister::isEmpty() const
	{
		return (m_contentVolume < 0.00001);
	}

	bool Canister::hasSameContent(const Canister& C) const
	{
		return m_contentName && C.m_contentName && strCmp(m_contentName, C.m_contentName) == 0;
	}

	Canister::Canister()
	{
		setToDefault();
	}

	Canister::Canister(const char* contentName)
	{
		setToDefault();
		setName(contentName);
	}

	Canister::Canister(double height, double diameter, const char* contentName)
	{
		setToDefault();
		if (height >= 10 && height <= 40 && diameter >= 10 && diameter <= 30) {
			m_height = height;
			m_diameter = diameter;
			m_contentVolume = 0.0;
			setName(contentName);
		}
		else {
			m_usable = false;
		}
	}

	Canister::~Canister()
	{
		delete[] m_contentName;
		m_contentName = nullptr;
	}

	Canister& Canister::setContent(const char* contentName)
	{
		if (!contentName || contentName[0] == '\0') {
			m_usable = false;
		}
		else if (isEmpty()) {
			setName(contentName);
		}
		else if (strCmp(m_contentName, contentName)) {
			m_usable = false;
		}


		return *this;
	}

	Canister& Canister::pour(double quantity)
	{
		if (m_usable && quantity > 0 && (quantity + volume()) <= capacity()) {
			m_contentVolume += quantity;
		}
		else {
			m_usable = false;
		}

		return *this;
	}

	Canister& Canister::pour(Canister& C)
	{
		//if (hasSameContent(C)) {
			setContent(C.m_contentName);
			if (C.volume() > (capacity() - volume())) {
				C.m_contentVolume -= capacity() - volume();
				m_contentVolume = capacity();
			}
			else {
				pour(C.m_contentVolume);
				C.m_contentVolume = 0.0;
			}
		/*}
		else {
			m_usable = false;
		}*/

		return*this;
	}

	double Canister::volume() const
	{
		return m_contentVolume;
	}

	std::ostream& Canister::display() const
	{
		cout.setf(ios::fixed);
		cout.precision(1);
		cout.width(7);
		cout << capacity() << "cc (" << m_height << "x" << m_diameter << ") Canister";
		if (!m_usable) {
			cout << " of Unusable content, discard!";
		}
		else if(m_contentName != nullptr) {
			cout << " of ";
			cout.width(7);
			cout << volume() << "cc   " << m_contentName;
		}

		cout.unsetf(ios::fixed);
		return cout;
	}

	double Canister::capacity() const
	{
		return PI * (m_height - 0.267) * (m_diameter / 2) * (m_diameter/ 2);
	}

	void Canister::clear()
	{
		if (!m_usable) {
			delete[] m_contentName;
			m_contentName = nullptr;
			m_contentVolume = 0.0;
			m_usable = true;
		}
	}
}