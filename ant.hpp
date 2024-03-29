/***************************************************************
** Author:      Alexandru Mocanu
** Date:        09/01/2019
** Project:     Langton's Ant
** Description: Ant Class header file. Creates a dynamically
                allocated 2D array that represents the board with
                specifications gathered from the user.
                Runs the simulation and prints the board with every
                step.
***************************************************************/

#ifndef ANT_HPP
#define ANT_HPP

class Ant
{
private:
    //variables to hold the dimensions of the board
    int cols;
    int rows;
    //variable to hold the number of steps for the ant to take
    int steps;
    //variable to keep track of the ant's current location
    int ant_row;
    int ant_col;
    //board is a pointer to a two-dimensional array of pointers
    char** board;
    //variable to hold where the ant is facing (W - west, N - north, E - east, S - south)
    char direction;
    int stepCounter;
public:
    Ant(int, int, int, int, int);
    ~Ant();
    void print_board();
    void run_simulation();
    void check_border();
};

#endif
