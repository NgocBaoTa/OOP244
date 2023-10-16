#include "Menu.h"
#include <cstring>
#include <iostream>
#include "Utils.h"

using namespace std;
namespace sdds {
	MenuItem::MenuItem(const char*word = NULL) {
		if (word) {
			menucontent = new char[strLen(word)+1];
			strCpy(menucontent, word);
		}
		else {
			menucontent = nullptr;
		}
	}
	//MenuItem::MenuItem() {
	//	menucontent = nullptr;
	//}
	MenuItem::~MenuItem() {
        if (menucontent != nullptr) {
            delete[]menucontent;
            menucontent = nullptr;

        }
	}
	MenuItem::operator bool() {
        if (menucontent) {
            return true;
        }
        return false;
	}
	MenuItem::operator const char* ()const {
	//return menucontent;
        return &menucontent[0];
	}

    void MenuItem::display(std::ostream& os) const
    {
        if (menucontent != nullptr) {
            os << menucontent;
        }
    }
	Menu::Menu() {
        title = nullptr;
        count = 0;
        for (unsigned int i = 0; i < MAX_MENU_ITEMS; ++i) {
            menuitem[i] = nullptr;
        }
	}
	Menu::Menu(const char* menutitle) {
		if (menutitle != nullptr) {
			title = new char[strLen(menutitle) + 1];
			strCpy(title, menutitle);
		}
        for (unsigned int i = 0; i < MAX_MENU_ITEMS; ++i) {
            menuitem[i] = nullptr;
        }
		count = 0;
	}
	Menu::~Menu() {
        if (menuitem) {
            for (unsigned int i = 0; i < count; ++i) {
                delete menuitem[i];
                menuitem[i] = nullptr;
            }
        }

        delete[] title;
        title = nullptr;
        count = 0;
	}
   /* std::ostream& Menu::displaytitle(std::ostream& os) const {
        if (title) {
            os << title << ":\n";
        }
        return os;
    }
	
        std::ostream& Menu::viewmenu(std::ostream& os) const {
            displaytitle(os);
            unsigned i;
            for ( i = 0; i < count; i++) {
                os << " " << i + 1 << "- ";
                menuitem[i]->display(os);
                os << "\n";
            }
            os << " 0- Exit" << endl;
            os << "> ";
            return os;
        }*/

        void Menu::displaytitle(std::ostream& os) const
        {
            if (title) {
                os << title << ":\n";
            }
        }

        void Menu::viewmenu(std::ostream& os) const
        {
            displaytitle(os);
            unsigned i;
            for (i = 0; i < count; i++) {
                os << " " << i + 1 << "- ";
                menuitem[i]->display(os);
                os << "\n";
            }
            os << " 0- Exit" << endl;
            os << "> ";
        }

        unsigned int Menu::run() {
            viewmenu(cout);
            int select;           
            bool valid = false;
            while (!valid) {
                cin >> select;

                if (cin.fail() || select < 0 || select > count) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "Invalid Selection, try again: ";
                }
                else {
                    cin.ignore(10000, '\n');
                    valid = true;
                }
            }
            return select;
        }

        unsigned int Menu::operator~() {
            return run();
        }

        Menu& Menu::operator<<(const char* menuitemContent) {
            if (count < (int)MAX_MENU_ITEMS) {
                MenuItem* newMenuItem = new MenuItem(menuitemContent);
                menuitem[count] = newMenuItem;
                ++count;
            }
            return *this;
        }

        Menu::operator int() const {
            return count;
        }

        Menu::operator unsigned int() const {
            return count;
        }

        Menu::operator bool() const {
            return count > 0;
        }

        const char* Menu::operator[](unsigned int index) const {
            if (count > 0) {
                int adjustedIndex = index % count;
                return menuitem[adjustedIndex]->operator const char* ();

            }
            return nullptr;
        }

        std::ostream& operator<<(std::ostream& ostr, const Menu& menu) {
            if (menu.title) {
                ostr << menu.title;
            }
            return ostr;
        }

}