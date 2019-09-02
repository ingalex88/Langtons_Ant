#ifndef MENU_HPP
#define MENU_HPP

class Menu
{
private:
    int first_menu_option;
    int columns;
    int rows;
    int starting_row;
    int starting_column;
    int steps;

public:
    Menu();
    ~Menu();
    int mainMenu();
    void about_Langtons_Ant();
    void get_data();
    void run_Langtons_Ant();
    int start();
};
#endif // MENU_HPP
