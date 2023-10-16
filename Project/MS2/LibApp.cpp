// Final Project Milestone 2
// LibApp Module
// File	LibApp.cpp
// Version 1.0
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name: Bao Ngoc Ta               
// Date: 07/19/2023              
// Authenticity Declaration :
// I have done all the coding by myself and only copied the code that my
// professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <cstring>
#include "LibApp.h"
#include "Menu.h"
using namespace std;
namespace sdds {
    LibApp::LibApp() :
        m_changed(false), 
        m_mainMenu("Seneca Library Application"), 
        m_exitMenu("Changes have been made to the data, what would you like to do?")
    {
        m_mainMenu << "Add New Publication" <<
            "Remove Publication" <<
            "Checkout publication from library" <<
            "Return publication to library";
        m_exitMenu << "Save changes and exit" <<
            "Cancel and go back to the main menu"; 
        load();
    }

    void LibApp::run()
    {
        int choice;
        bool done = false;
        while (!done) {
            switch (choice = m_mainMenu.run())
            {
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
                if (m_changed) {
                    int newChoice = m_exitMenu.run();
                    if (newChoice == 1) {
                        save();
                        done = true;
                        cout << "\n-------------------------------------------\n" <<
                            "Thanks for using Seneca Library Application\n";
                    }
                    else if(newChoice == 0) {
                        if (confirm("This will discard all the changes are you sure?")) {
                            done = true;
                            cout << "\n-------------------------------------------\n" <<
                                "Thanks for using Seneca Library Application\n";
                        }
                    }
                    else {
                        cout << "\n";
                    }
                    
                }
                else {
                    done = true;
                    cout << "\n-------------------------------------------\n" <<
                        "Thanks for using Seneca Library Application\n";
                }
                
                break;
            }
        }

        
    }

    void LibApp::load()
    {
        cout << "Loading Data\n";
    }

    void LibApp::save()
    {
        cout << "Saving Data\n";
    }

    void LibApp::search()
    {
        cout << "Searching for publication\n";
    }

    void LibApp::returnPub()
    {
        search();
        cout << "Returning publication\n";
        cout << "Publication returned\n\n";
        m_changed = true;
    }

    bool LibApp::confirm(const char* message)
    {
        Menu newMenu(message);
        newMenu << "Yes";
        return newMenu.run() == 1;
    }

    void LibApp::newPublication()
    {
        cout << "Adding new publication to library\n";
        if (confirm("Add this publication to library?")) {
            m_changed = true;
            cout << "Publication added\n\n";
        }
        else {
            cout << "\n";
        }
    }

    void LibApp::removePublication()
    {
        cout << "Removing publication from library\n";
        search();
        if (confirm("Remove this publication from the library?")) {
            m_changed = true;
            cout << "Publication removed\n\n";
        }
    }

    void LibApp::checkOutPub()
    {
        search();
        if (confirm("Check out publication?")) {
            m_changed = true;
            cout << "Publication checked out\n\n";
        }
    }

}