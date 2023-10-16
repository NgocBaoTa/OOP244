#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "LblShape.h"
using namespace std;
namespace sdds {
	const char* LblShape::label() const
	{
		return m_label;
	}

	LblShape::LblShape()
	{
			m_label = nullptr;
		
	}

	LblShape::LblShape(const char* label)
	{
		if (label != nullptr && label[0] != '\0') {

		m_label = new char[strlen(label) + 1];
		strcpy(m_label, label);
		}
	}

	LblShape::~LblShape()
	{
		delete[] m_label;
		m_label = nullptr;
	}

	void LblShape::getSpecs(istream& is)
	{
		string label;
		getline(is, label, ',');
		delete[] m_label;
		m_label = new char[label.length() + 1];
		strcpy(m_label, label.c_str());
	}


}


