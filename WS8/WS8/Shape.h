#pragma once
#ifndef SDDS_SHAPE_H_
#define SDDS_SHAPE_H_
#include <iostream>
using namespace std;
namespace sdds {
    class Shape {
    public: 
        virtual void draw(ostream& os) const = 0;
        virtual void getSpecs(istream& is) = 0;
        virtual ~Shape() ;
    };

    istream& operator>>(istream& is, Shape& shape);
    ostream& operator<<(ostream& os, const Shape& shape);
}
#endif
