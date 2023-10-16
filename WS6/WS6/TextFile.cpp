/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #6 (P1)
Full Name  : Bao Ngoc Ta
Student ID#: 116038225
Email      : bta@myseneca.ca
Date	   : 07/07/2023
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include "TextFile.h"
#include "cstring.h"
using namespace std;
namespace sdds {
    Line::operator const char* () const {
        return (const char*)m_value;
    }
    Line& Line::operator=(const char* lineValue) {
        delete[] m_value;
        m_value = new char[strLen(lineValue) + 1];
        strCpy(m_value, lineValue);
        return *this;
    }
    Line::~Line() {
        delete[] m_value;
    }

    //==================================================================================

    void TextFile::setFilename(const char* fname, bool isCopy)
    {
        if (isCopy) {
            m_filename = new char[strLen("C_") + strLen(fname) + 1];
            strCpy(m_filename, "C_");
            strCat(m_filename, fname);
        }
        else {
            m_filename = new char[strLen(fname) + 1];
            strCpy(m_filename, fname);
        }
    }

    void TextFile::setNoOfLines()
    {
        ifstream f(m_filename);
        char ch;
        if (f.is_open()) {
            while (f) {
                f.get(ch);
                if (ch != '\n') {
                    m_noOfLines++;
                }
            }
            m_noOfLines++;
        }
        else {
            delete[] m_filename;
            m_filename = nullptr;
        }
    }

    void TextFile::loadText()
    {
        if (m_filename != nullptr) {
            delete[] m_textLines;
            m_textLines = new Line[m_noOfLines];
            ifstream f(m_filename);

            string m_line;
            unsigned count = 0;
            if (f.is_open()) {
                while (getline(f, m_line)) {
                    m_textLines[count].m_value = new char[strLen(m_line.c_str()) + 1];
                    strCpy(m_textLines[count].m_value, m_line.c_str());
                    count++;
                }

            }
            m_noOfLines = count;
        }
    }

    void TextFile::saveAs(const char* fileName) const
    {
        ofstream f(fileName);
        if (f.is_open()) {
            for (unsigned i = 0; i < m_noOfLines; i++) {
                f << m_textLines[i] << std::endl;
            }
        }
    }

    void TextFile::setEmpty()
    {
        if (m_textLines != nullptr) {
            delete[] m_textLines;
            m_textLines = nullptr;
        }

        if (m_filename != nullptr) {
            delete[] m_filename;
            m_filename = nullptr;
        }

        m_noOfLines = 0;
    }

    TextFile::TextFile(unsigned pageSize)
    {
        setEmpty();
        m_pageSize = pageSize;
    }

    TextFile::TextFile(const char* filename, unsigned pageSize)
    {
        setEmpty();
        m_pageSize = pageSize;
        if (filename) {
            setFilename(filename);
            setNoOfLines();
            loadText();
        }
    }

    TextFile::TextFile(const TextFile& file)
    {
        setEmpty();
        this->m_pageSize = file.m_pageSize;
        if (this != &file) {
            if (file.m_textLines && file.m_noOfLines > 0) {
                setFilename(file.m_filename, true);
                this->m_noOfLines = file.m_noOfLines;
                m_textLines = new Line[m_noOfLines];
                for (unsigned i = 0; i < m_noOfLines; i++) {
                    m_textLines[i].m_value = new char[strLen(file.m_textLines[i].m_value) + 1];
                    strCpy(m_textLines[i].m_value, file.m_textLines[i].m_value);
                }
                saveAs(m_filename);
            }
        }
    }

    TextFile& TextFile::operator=(const TextFile& file)
    {
        if (this != &file) {
            if (file.m_textLines && file.m_noOfLines > 0 && this->m_textLines && this->m_noOfLines > 0) {
                if (m_textLines != nullptr) {
                    delete[] m_textLines;
                    m_textLines = nullptr;
                }
                this->m_noOfLines = file.m_noOfLines;
                m_textLines = new Line[m_noOfLines];
                for (unsigned i = 0; i < m_noOfLines; i++) {
                    m_textLines[i].m_value = new char[strLen(file.m_textLines[i].m_value) + 1];
                    strCpy(m_textLines[i].m_value, file.m_textLines[i].m_value);
                }
                saveAs(m_filename);
            }
        }
            return *this;
    }

    TextFile::~TextFile()
    {
        if (m_textLines != nullptr) {
            delete[] m_textLines;
            m_textLines = nullptr;
        }

        if (m_filename != nullptr) {
            delete[] m_filename;
            m_filename = nullptr;
        }
    }
   

    std::ostream& TextFile::view(std::ostream& ostr) const
    {
        if (m_filename) {
            ostr << m_filename << endl;
            ostr.fill('=');
            ostr.width(strLen(m_filename));
            ostr << '=' << endl;
            for (unsigned i = 0; i < m_noOfLines; i++) {
                unsigned j = 0;
                do {
                    ostr << m_textLines[i] << endl;
                    i++; 
                    j++;
                    if (j == m_pageSize) {
                        ostr << "Hit ENTER to continue...";
                        char x;
                        cin.get(x);
                        j = 0;
                    }
                } while (j < m_pageSize && i < m_noOfLines);
            }
        }

        return ostr;
    }

    std::istream& TextFile::getFile(std::istream& istr)
    {
                                                                                                
        string m_name;
        istr >> m_name;
        m_filename = new char[strLen(m_name.c_str()) + 1];
        strCpy(m_filename, m_name.c_str());
        istr.ignore(10000, '\n');
        setNoOfLines();
        loadText();
        return istr;
    }

    TextFile::operator bool() const
    {
        bool result = false;
        if (m_noOfLines > 0 && m_textLines) {
            result = true;
        }
        return result;
    }

    unsigned TextFile::lines() const
    {
        return m_noOfLines;
    }

    const char* TextFile::name() const
    {
        return m_filename;
    }

    const char* TextFile::operator[](unsigned index) const
    {
        if (m_textLines) {
            if (index > m_noOfLines - 1) {
                index -= m_noOfLines;
            }

            return m_textLines[index].m_value;
        }
        else {
            return NULL;
        }
    }

    std::ostream& operator<<(std::ostream& ostr, const TextFile& text)
    {
        text.view(ostr);
        return ostr;
    }

    std::istream& operator>>(std::istream& istr, TextFile& text)
    {
        text.getFile(istr);
        return istr;
    }
}

