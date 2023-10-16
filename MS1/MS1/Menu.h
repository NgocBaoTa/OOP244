#ifndef SDDS_MENU_H
#define SDDS_MENU_H
#include <iostream>
namespace sdds{
	const int MAX_MENU_ITEMS = 20;
	class MenuItem {
	private:
		char* menucontent{ nullptr };
		friend class Menu;
		MenuItem();
		MenuItem(const char*word);
		MenuItem(MenuItem& menuitem) = delete;
		MenuItem& operator=(const MenuItem& menuitem) = delete;
		~MenuItem();
		operator bool();
	    operator const char*()const;
		/*std::ostream& write(std::ostream& os = std::cout)const;*/
		void display(std::ostream& os) const;
	};
	class Menu {
	private:
		unsigned int count;
		char* title{ nullptr };
		MenuItem* menuitem[MAX_MENU_ITEMS]{ nullptr };
		Menu(Menu& menu) = delete;
		Menu& operator=(const Menu& menuitem) = delete;
	public:
		Menu();
		Menu(const char*menutitle);
		~Menu();		
		/*std::ostream& displaytitle(std::ostream& os=std::cout)const;
		std::ostream& viewmenu(std::ostream& os=std::cout)const;*/

		void displaytitle(std::ostream& os) const;
		void viewmenu(std::ostream& os) const;
		unsigned int run();
		unsigned int operator~();
		Menu& operator<<(const char* menuitemConent);
		operator int() const;
		operator unsigned int() const;
		operator bool() const;
		const char* operator[](unsigned int index) const;
	friend std::ostream& operator<<(std::ostream& ostr, const Menu& menu);
	};



}
#endif // 
