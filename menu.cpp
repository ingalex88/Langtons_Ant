/***************************************************************
** Author:      Alexandru Mocanu
** Date:        09/01/2019
** Project:     Langton's Ant
** Description: Menu Class implementation file
***************************************************************/

#include "menu.hpp"
#include "ant.hpp"
#include "user_validation.hpp"

#include <string>
#include <iostream>
#include <cstdlib>//to use srand, rand
#include <chrono>
#include <thread>
#include <unistd.h>
#include <time.h>


using std::string;
using std::cout;
using std::cin;
using std::endl;

/**
Default constructor of Menu class;
initializes data members;
**/
Menu::Menu()
{
    first_menu_option = 0;
    columns = 0;
    rows = 0;
    starting_row = 0;
    starting_column = 0;
    steps = 0;

    srand(time(0));
}

/**
Default constructor of Menu class;
**/
Menu::~Menu()
{
    //constructor left empty
}

/**
Method prints the initial menu options and prompts user to make a selection;
Validates the user's selection and returns integer to the program;
**/
int Menu::mainMenu()
{
    cout << "\n\n\tLangton's Ant" << endl;
    cout << "\t    By Alexandru Mocanu" << endl;

    cout << "\n  1. About Langton's Ant\n  2. Start Langton's Ant\n  3. Quit" << endl;
    cout << "\n  Please make a selection by typing the number next to your desired menu option: ";

    string user_number;
    getline(cin, user_number);
    //validating the user input using the user_val function
    first_menu_option = user_val(user_number, 1, 3);

    return first_menu_option;
}

/**
Prints information about the simulation
**/
void Menu::about_Langtons_Ant()
{
    std::chrono::seconds timespan(2);//setting a time of 2 seconds for the program to "sleep" between lines
    cout << "\n  Langton's ant is a two-dimensional universal Turing machine with a very simple set of rules." << endl;
    std::this_thread::sleep_for(timespan);
    cout << "  The ant is placed on a grid board that is filled with white spaces and starts moving forward." << endl;
    std::this_thread::sleep_for(timespan);
    cout << "\n  For each step forward, the ant will follow 2 rules:" << endl;
    std::this_thread::sleep_for(timespan);
    cout << "\t- If the ant is on a WHITE space, turn RIGHT 90 degrees and change the space to BLACK" << endl;
    std::this_thread::sleep_for(timespan);
    cout << "\t- If the ant is on a BLACK space, turn LEFT 90 degrees and change the space to WHITE" << endl;
    std::this_thread::sleep_for(timespan);
    cout << "\n  Press ENTER to continue ";
    getchar;
}

/**
Prompts user to enter information about the program/simulation
**/
void Menu::get_data()
{
    cout << "\n  How high would you like your grid/board to be (how many rows)?" << endl;
    cout << "  Enter a number between 4 and 100: ";
    string height;
    getline(cin, height);
    rows = user_val(height, 4, 100);

    cout << "\n  How long would you like your gird/board to be (how many columns)?" << endl;
    cout << "  Enter a number between 4 and 100: ";
    string length;
    getline(cin, length);
    columns = user_val(length, 4, 100);

    cout << "\n  Now it is time to put the ant on the board" << endl;
    cout << "           1. Place the ant randomly" << endl;
    cout << "           2. Specify the starting location" << endl;
    cout << "\n  Your selection: ";
    string location;
    getline(cin, location);
    int locationOption = user_val(location, 1, 2);

    if(locationOption == 1)
    {
        starting_row = rand() % rows + 1;
        starting_column = rand() % columns + 1;
        cout << "\n  The randomly generated starting point is: " << endl;
        cout << "       - Starting Row: " << starting_row << endl;
        cout << "       - Starting Column: " << starting_column << endl;
    }
    else if(locationOption == 2)
    {
        cout << "\n  Please enter the starting Row (a number between 1 and " << rows << "): ";
        string startingRow;
        getline(cin, startingRow);
        starting_row = user_val(startingRow, 1, rows);

        cout << "\n  Please enter the starting Column (a number beween 1 and " << columns << "): ";
        string startingCol;
        getline(cin, startingCol);
        starting_column = user_val(startingCol, 1, columns);
    }

    cout << "\n  Finally, how many steps would you like the ant to take?" << endl;
    cout << "  Enter a number between 2 and 10,000: ";
    string stepsStr;
    getline(cin, stepsStr);
    steps = user_val(stepsStr, 2, 10000);

    cout << "\n\n  Here is the information about the simulation:" << endl;
    cout << " ***********************************************" << endl;
    cout << "  Board size:" << endl;
    cout << "     - Rows: " << rows << endl;
    cout << "     - Columns: " << columns << endl;
    cout << "  Ant starting Location:" << endl;
    cout << "     - Starting Row: " << starting_row << endl;
    cout << "     - Starting Column: " << starting_column << endl;
    cout << "  Number of steps: " << steps << endl;
    cout << "\n  Press ENTER to start the simulation ";
    getchar();
}

/**
Runs the simulation by creating an Ant object, passing it the necessary information,
and calling its 'run_simulation' method
**/
void Menu::run_Langtons_Ant()
{
    //calling the get_data() function in order to collect the necessary information from the user
    get_data();
    //creating an Ant object and passing the necessary parameters
    Ant Langtons_Ant(rows, columns, steps, starting_row, starting_column);
    Langtons_Ant.run_simulation();
}

/**
Loop that will continue as long as the user does not wishes to quit
**/
int Menu::start()
{
    while(first_menu_option != 3)
    {
        mainMenu();
        if(first_menu_option == 1)
        {
            about_Langtons_Ant();
        }
        else if(first_menu_option == 2)
        {
            run_Langtons_Ant();
        }
    }
    return 0;
}
