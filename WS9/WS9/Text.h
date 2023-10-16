// Final Project Milestone 1 
// Text Module
// File	Text.h
// Version 1.0
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name: Bao Ngoc Ta               
// Date: 07/27/2023              
// Authenticity Declaration :
// I have done all the coding by myself and only copied the code that my
// professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////

#ifndef SDDS_TEXT_H__
#define SDDS_TEXT_H__
#include <iostream>
namespace sdds {
    class Text {
        char* m_filename{ nullptr };
        char* m_content{ nullptr };
        int getFileLength()const;
    protected:
        const char& operator[](int index)const;
    public:
        Text(const char* filename = nullptr);
        virtual ~Text();
        Text(const Text& text);
        Text& operator=(const Text& text);

        void read();
        virtual void write(std::ostream& os)const;
    };

    std::ostream& operator<<(std::ostream& os, const Text& text);
}
#endif // !SDDS_PERSON_H__