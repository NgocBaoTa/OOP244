// Final Project Milestone 1 
// HtmlText Module
// File	HtmlText.h
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

#ifndef SDDS_HTMLTEXT_H__
#define SDDS_HTMLTEXT_H__
#include "Text.h"
namespace sdds {
    class HtmlText : public Text {
        char* m_title{ nullptr };
    public:
        HtmlText(const char* filename = nullptr, const char* title = nullptr);
        HtmlText(const HtmlText& text);
        ~HtmlText();
        HtmlText& operator=(const HtmlText& src);

        void write(std::ostream& os)const override;

    };
}
#endif // !SDDS_HTMLTEXT_H__