#pragma once
#ifndef SDDS_LBLSHAPE_H__
#define SDDS_LBLSHAPE_H__
#include <iostream>
#include "Shape.h"
using namespace std;
namespace sdds {
    class LblShape : public Shape {
        char* m_label{ nullptr };
    protected: 
        const char* label() const;
    public:
        LblShape();
        LblShape(const char* label);
        ~LblShape();
        LblShape(const LblShape&) = delete;
        LblShape& operator=(const LblShape&) = delete;
        void getSpecs(istream& is) override;
    };
}
#endif