#include "menu.hpp"

#include <string>
#include <iostream>
#include "user_validation.hpp"

using std::string;
using std::cout;
using std::cin;
using std::endl;

Menu::Menu()
{

}

Menu::~Menu()
{

}

int Menu::mainMenu()
{
    cout << "\n\tLangton's Ant" << endl;
    cout << "\t    By Alexandru Mocanu" << endl;

    cout << "\n  1. About Langton's Ant\n  2. Start Langton's Ant\n  3. Quit" << endl;
    cout << "\n  Please make a selection by typing the number next to your desired menu option: ";

    string user_number;
    getline(cin, user_number);
    //validating the user input using the user_val function
    first_menu_option = user_val(user_number, 1, 3);

    cout << "\n  You selected " << first_menu_option << endl;

    return first_menu_option;
}
