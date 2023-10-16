// Final Project Milestone 2
// LibApp Module
// File	LibApp.cpp
// Version 1.0
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name: Bao Ngoc Ta               
// Date: 07/29/2023              
// Authenticity Declaration :
// I have done all the coding by myself and only copied the code that my
// professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstring>
#include "LibApp.h"
#include "Menu.h"
#include "Book.h"
#include "Publication.h"
#include "PublicationSelector.h"
using namespace std;
namespace sdds {
    LibApp::LibApp(const char* fileName) :
        m_changed(false),
        m_mainMenu("Seneca Library Application"),
        m_exitMenu("Changes have been made to the data, what would you like to do?"),
        m_typeMenu("Choose the type of publication:")
    {
        if (fileName)
        {
            strcpy(m_filename, fileName);
        }

        m_changed = false;

        m_NOLP = 0;
        m_mainMenu << "Add New Publication" <<
            "Remove Publication" <<
            "Checkout publication from library" <<
            "Return publication to library";
        m_exitMenu << "Save changes and exit" <<
            "Cancel and go back to the main menu";
        m_typeMenu << "Book" << "Publication";
        load();
    }

    LibApp::~LibApp()
    {
        for (int i = 0; i < m_NOLP; i++) {
            delete m_PPA[i];
        }
    }

    void LibApp::run() {
        int choice, existChoice;

        do {
            choice = m_mainMenu.run();

            switch (choice) {

            case 1:
                newPublication();
                break;
            case 2:
                removePublication();
                break;
            case 3:
                checkOutPub();
                break;
            case 4:
                returnPub();
                break;

            default:
                if (m_changed == true) {
                    existChoice = m_exitMenu.run();

                    switch (existChoice) {
                    case 0:
                        if (confirm("This will discard all the changes are you sure?")) {
                            m_changed = false;
                        }
                        break;
                    case 1:
                        save();
                        break;
                    case 2:
                        choice = 1;
                        break;
                    }
                }
                cout << endl;
            }
        } while (choice != 0);

        cout << "-------------------------------------------" << endl;
        cout << "Thanks for using Seneca Library Application" << endl;
    }

    Publication* LibApp::getPub(int libRef)
    {
        Publication* pub = nullptr;

        for (int i = 0; i < m_NOLP; i++)
        {
            if (m_PPA[i]->getRef() == libRef) {
                pub = m_PPA[i];
            }
        }

        return pub;
    }

    void LibApp::load()
    {
        cout << "Loading Data\n";
        ifstream f(m_filename);

        char type;
        for (int i = 0; i < SDDS_LIBRARY_CAPACITY && f; i++) {
            f >> type;
            f.ignore();
            if (f) {
                if (type == 'B') m_PPA[i] = new Book;
                else if (type == 'P') m_PPA[i] = new Publication;
                if (m_PPA[i]) {
                    f >> *m_PPA[i];
                    m_NOLP++;

                    m_LLRN = m_PPA[i]->getRef();
                }

            }

        }
    }

    void LibApp::save()
    {
        cout << "Saving Data\n";
        ofstream f(m_filename);

        for (int i = 0; i < m_NOLP; i++) {
            if (m_PPA[i]->getRef() != 0) {
                f << *m_PPA[i] << '\n';                        
            }
        }

        f.close();
    }

    int LibApp::search(int searchType)
    {
        PublicationSelector pubSel("Select one of the following found matches:");
        int selectedType = m_typeMenu.run();
        char type;
        if (selectedType == 1) type = 'B';
        else if (selectedType == 2) type = 'P';
        cin.ignore(1000, '\n');
        cout << "Publication Title: ";
        char title[256]{};
        cin.getline(title, 256);

        if (searchType == 1) {
            for (int i = 0; i < m_NOLP; i++) {
                if (m_PPA[i]->getRef() != 0 && m_PPA[i]->operator==(title) && m_PPA[i]->type() == type) {
                    pubSel << m_PPA[i];
                }
            }
        }

        if (searchType == 2) {
            for (int i = 0; i < m_NOLP; i++) {
                if (m_PPA[i]->getRef() != 0 && m_PPA[i]->operator==(title) && m_PPA[i]->type() == type && m_PPA[i]->onLoan()) {
                    pubSel << m_PPA[i];
                }
            }
        }

        if (searchType == 3) {
            for (int i = 0; i < m_NOLP; i++) {
                if (m_PPA[i]->getRef() != 0 && m_PPA[i]->operator==(title) && m_PPA[i]->type() == type && !m_PPA[i]->onLoan()) {
                    pubSel << m_PPA[i];
                }
            }
        }

        int libRef = 0;

        if (pubSel) {
            pubSel.sort();
            libRef = pubSel.run();
            if (libRef > 0)
            {
                cout << *getPub(libRef) << endl;
            }
            else {
                cout << "Aborted!\n";
            }
        }
        else {
            cout << "No matches found!\n";
        }

        return libRef;
    }

    void LibApp::returnPub()
    {
        cout << "Return publication to the library\n";
        int libRef = search(2);

        if (libRef > 0) {
            if (confirm("Return Publication?")) {
                int days = Date() - getPub(libRef)->checkoutDate();

                if (days > SDDS_MAX_LOAN_DAYS) {
                    double penalty = (days - SDDS_MAX_LOAN_DAYS) * 0.5;
                    cout << fixed << setprecision(2) << "Please pay $" << penalty << " penalty for being " << (days - SDDS_MAX_LOAN_DAYS) << " days late!" << endl;
                }

                getPub(libRef)->set(0);
                m_changed = true;
            }
        cout << "Publication returned\n";
        }
        cout << "\n";
    }

    bool LibApp::confirm(const char* message)
    {
        Menu newMenu(message);
        newMenu << "Yes";
        return newMenu.run() == 1;
    }

    void LibApp::newPublication()
    {
        bool exit = false;
        if (m_NOLP == SDDS_LIBRARY_CAPACITY) {
            cout << "Library is at its maximum capacity!\n";
            exit = true;
        }
        
        if (!exit) {
            cout << "Adding new publication to the library\n";
            int type = m_typeMenu.run();
            cin.ignore(1000, '\n');
            Publication* pub = nullptr;
            if (type == 0) {
                cout << "Aborted!\n";
                exit = true;
            }
            else if (type == 1) {
                pub = new Book;
                cin >> *pub;
            }
            else if (type == 2) {
                pub = new Publication;
                cin >> *pub;
            }

            if (cin.fail()) {
                cin.ignore(1000, '\n');
                cin.clear();
                cout << "Aborted!\n";
                exit = true;
            }
            else {
                if (!exit && confirm("Add this publication to the library?")) {
                    if (*pub) {
                        m_LLRN++;
                        pub->setRef(m_LLRN);
                        m_PPA[m_NOLP] = pub;
                        m_NOLP++;
                        m_changed = true;
                        cout << "Publication added\n";
                    }
                    else {
                        cout << "Failed to add publication!\n";
                        delete pub;
                    }
                }
            }
        }
        cout << endl;
    }

    void LibApp::removePublication()
    {
        cout << "Removing publication from the library\n";
        int libRef = search(1);
        if (libRef) {
            if (confirm("Remove this publication from the library?")) {
                getPub(libRef)->setRef(0);
                m_changed = true;
                cout << "Publication removed\n";
            }
        }
        cout << '\n';
    }

    void LibApp::checkOutPub()
    {
        cout << "Checkout publication from the library\n";
        int libRef = search(3);
        if (libRef) {
            if (confirm("Check out publication?")) {
                cout << "Enter Membership number: ";
                bool valid = false;
                int memNumber;
                while (!valid) {
                    cin >> memNumber;
                    if (!cin || memNumber < 10000 || memNumber > 99999) {
                        cout << "Invalid membership number, try again: ";
                        cin.clear();
                        cin.ignore(1000, '\n');
                        valid = false;
                    }
                    else {
                        valid = true;
                    }
                }

                getPub(libRef)->set(memNumber);
                m_changed = true;
                cout << "Publication checked out\n";
            }
        }
        cout << '\n';
    }

}
