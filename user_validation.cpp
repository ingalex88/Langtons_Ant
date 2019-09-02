/**
user_val method is used to validate user input; method accepts a string and two
integers as parameters; converts string to integer and checks if value is
within the lower and higher limits passed as parameters; if condition is met
it returns the number; if condition is not met, it prompts the user for
another entry
**/

#include "user_validation.hpp"

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;

int user_val(std::string line, int lower, int upper)
{
    std::stringstream ss(line);
    int select = 0;
    if(ss >> select)
        {//cited from https://stackoverflow.com/questions/10828937/how-to-make-cin-take-only-numbers
            if(ss.eof())
            {
                if(select >= lower && select <= upper)
                {
                    return select;
                }
            }
        }
        cout << "\tNot a valid entry. Please try again" << endl;

    while(std::getline(std::cin, line))
    {
        std::stringstream ss(line);
        if(ss >> select)
        {//cited from https://stackoverflow.com/questions/10828937/how-to-make-cin-take-only-numbers
            if(ss.eof())
            {
                if(select >= lower && select <= upper)
                {
                    return select;
                }
            }
        }
        cout << "\tNot a valid entry. Please try again" << endl;
    }
}
