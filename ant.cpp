#include <iostream>
#include "ant.hpp"

using std::cout;

Ant::Ant(int numRows, int numColumns, int numSteps)
{
    //adding 2 to the cols and rows to account for the board border that will be added later on
    cols = numColumns + 2;
    rows = numRows + 2;
    steps = numSteps;

    board = new char * [rows];
    for(int i = 0; i < rows; i++)
    {
        board[i] = new char [cols];
    }

    for(int x = 0; x < rows; x++)
    {
        for(int y = 0; y < cols; y++)
        {
            board[x][y] = 'x';
        }
    }
}

Ant::~Ant()
{
    //destructor left empty
}

void Ant::print_board()
{
    for(int i = 0; i < rows; i++)
    {
        board[i][0] = '|';
        board[i][cols - 1] = '|';
    }
    for(int i = 1; i < cols - 1; i++)
    {
        board[0][i] = '-';
        board[rows - 1][i] = '-';
    }

    cout << "\n\n\n";
    for(int x = 0; x < rows; x++)
    {
        cout << "\t";
        for(int y = 0; y < cols; y++)
        {
            cout << board[x][y];
        }
        cout << "\n";
    }
}

void Ant::run_simulation()
{
    print_board();

}

