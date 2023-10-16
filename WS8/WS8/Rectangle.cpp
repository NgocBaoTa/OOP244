#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <cstring>
#include "Rectangle.h"
using namespace std;
namespace sdds {
	Rectangle::Rectangle() : LblShape()
	{
		m_width = 0;
		m_height = 0;
	}

	Rectangle::Rectangle(const char* str, int width, int height) : LblShape(str)
	{
		if (height < 3 || (unsigned)width < (unsigned) (strlen(LblShape::label()) + 2)) {
			m_width = 0;
			m_height = 0;
		}
		else {
			m_width = width;
			m_height = height;
		}
	}

	void Rectangle::getSpecs(std::istream& is)
	{
		LblShape::getSpecs(is);
		is >> m_width;
		is.ignore();
		is >> m_height;
		is.ignore(1000, '\n');
	}

	void Rectangle::draw(std::ostream& os) const
	{
		if (m_width != 0 && m_height != 0) {
			os << "+" << setw(m_width) << setfill('-') << "+\n";
			os << "|" << setw(m_width - 2) << setfill(' ') << left << LblShape::label() << "|\n";
			for (int i = 0; i < m_height - 3; i++) {
				os << "|";
				os << right << setw(m_width - 1) << "|" << endl;
			};
			os << "+" << setw(m_width - 1) << setfill('-') << "+";
		}
	}


}




