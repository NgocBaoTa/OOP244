// Final Project Milestone 1 
// Text Module
// File	Text.cpp
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


#define _CRT_SECURE_NO_WARNINGS
#include "Text.h"
#include <fstream>
#include <iostream>
#include <cstring>
using namespace std;
namespace sdds {
    int Text::getFileLength() const {
        int len = 0;
        ifstream fin(m_filename);
        while (fin) {
            fin.get();
            len += !!fin;
        }
        return len;
    }

    const char& Text::operator[](int index) const
    {
        if (index >= 0 || index < getFileLength()) {
            return m_content[index];
        }
        else {
            return m_content[getFileLength()];
        }
    }

    Text::Text(const char* filename)
    {
        if (filename) {
            m_filename = new char[strlen(filename) + 1];
            strcpy(m_filename, filename);
            read();
        }
        else {
            m_content = nullptr;
            m_filename = nullptr;
        }
    }

    Text::~Text()
    {
        if (m_content) {
            delete[] m_content;
            m_content = nullptr;
        } 
        if (m_filename) {
            delete[] m_filename;
            m_filename = nullptr;
        }
    }

    Text::Text(const Text& text)
    {
        *this = text;
    }

    Text& Text::operator=(const Text& text)
    {
        if (this != &text) {
            if (m_filename) {
                delete[] m_filename;
                m_filename = nullptr;
            }

            if (text.m_filename) {
                m_filename = new char[strlen(text.m_filename) + 1];
                strcpy(m_filename, text.m_filename);
                read();
            }
            else {
                m_content = nullptr;
                m_filename = nullptr;
            }
        }

        return *this;
    }

    void Text::read()
    {
        char c;
        int i = 0;
        ifstream fin(m_filename);
        if (m_content) delete[] m_content;
        if (fin.is_open()) {
            m_content = new char[getFileLength() + 1];
            while (fin.get(c)) {
                m_content[i] = c;
                i++;
            }
            m_content[i] = '\0';
        }
        else {
            m_content = nullptr;
        }
    }

    void Text::write(std::ostream& os) const
    {
        if (m_content) os << m_content;
    }

    std::ostream& operator<<(std::ostream& os, const Text& text)
    {
        text.write(os);
        return os;
    }

}