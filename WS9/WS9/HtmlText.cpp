// Final Project Milestone 1 
// HtmlText Module
// File	HtmlText.cpp
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
#include "HtmlText.h"
#include <cstring>
#include <iostream>
using namespace std;
namespace sdds {
	HtmlText::HtmlText(const char* filename, const char* title) : Text(filename)
	{
		if (title) {
			m_title = new char[strlen(title) + 1];
			strcpy(m_title, title);
		}
		else {
			m_title = nullptr;
		}
	}

	HtmlText::HtmlText(const HtmlText& text)
	{
		*this = text;
	}

	HtmlText::~HtmlText()
	{
		if (m_title) {
			delete[] m_title;
			m_title = nullptr;
		}
	}

	HtmlText& HtmlText::operator=(const HtmlText& src)
	{
		if (this != &src) {
			(Text&)*this = src;
			if (m_title) {
				delete[] m_title;
				m_title = nullptr;
			}

			if (src.m_title) {
				m_title = new char[strlen(src.m_title) + 1];
				strcpy(m_title, src.m_title);
			} 
		}

		return *this;
	}


	void HtmlText::write(std::ostream& os) const
	{
		bool MS = false;
		os << "<html><head><title>";
		if (m_title) {
			os << m_title;
		}
		else {
			os << "No Title";
		}
		os << "</title></head>\n<body>\n";

		if (m_title) {
			os << "<h1>" << m_title << "</h1>\n";
			int index = 0;

			while (Text::operator[](index) != '\0') {
				char c = Text::operator[](index);
				switch (c)
				{
				case ' ':
					if (MS) {os << "&nbsp;";
					}
					else {
						MS = true;
						os << c;
					}
					break;
				case '<':
					os << "&lt;";
					MS = false;
					break;
				case '>':
					os << "&gt;";
					MS = false;
					break;
				case '\n':
					os << "<br />\n";
					MS = false;
					break;
				default:
					os << c;
					MS = false;
					break;
				}
				index++;
			}
			os << "</body>\n</html>";
		}
	}

}
