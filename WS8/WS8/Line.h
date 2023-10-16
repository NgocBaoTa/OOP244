#pragma once
#ifndef SDDS_LINE_H_
#define SDDS_LINE_H_
#include "LblShape.h"
#include <iostream>
namespace sdds {
	class Line : public LblShape {
		int m_length; 
	public:
		Line();
		Line(const char* str, int len);
		//~Line() {}; 

		void getSpecs(std::istream& is) override;
		void draw(std::ostream& os) const override;
	};
}
#endif