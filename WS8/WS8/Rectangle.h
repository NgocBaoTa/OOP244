#pragma once
#ifndef SDDS_RECTANGLE_H_
#define SDDS_RECTANGLE_H_
#include "LblShape.h"
#include <iostream>
namespace sdds {
	class Rectangle : public LblShape {
		int m_height;
		int m_width;
	public:
		Rectangle();
		Rectangle(const char* str, int width, int height);
		//~Rectangle() {};

		void getSpecs(std::istream& is) override;
		void draw(std::ostream& os) const override;
	};
}
#endif