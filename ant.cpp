#include <iostream>
#include "ant.hpp"
#include <string>

using std::cout;
using std::endl;

Ant::Ant(int numRows, int numColumns, int numSteps, int startRow, int startCol)
{
    //adding 2 to the cols and rows to account for the board border that will be added later on
    cols = numColumns + 2;
    rows = numRows + 2;
    steps = numSteps;
    ant_row = startRow;
    ant_col = startCol;

    board = new char * [rows];
    for(int i = 0; i < rows; i++)
    {
        board[i] = new char [cols];
    }

    //filling the board with blank spaces
    for(int x = 0; x < rows; x++)
    {
        for(int y = 0; y < cols; y++)
        {
            board[x][y] = ' ';
        }
    }

    //creating borders for the board
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

    //setting the initial ant direction to 'W - West' (screen left)
    direction = 'W';

    stepCounter = 0;
}

Ant::~Ant()
{
    for(int i = 0; i < rows; i++)
    {
        delete board[i];
    }

    delete [] board;
}

void Ant::print_board()
{
    std::string dirStr;
    if(direction == 'W')
    {
        dirStr = "west (left)";
    }
    else if(direction == 'N')
    {
        dirStr = "north (up)";
    }
    else if(direction == 'E')
    {
        dirStr = "east (right)";
    }
    else if(direction == 'S')
    {
        dirStr = "south (down)";
    }

    cout << "\n\n\n";
    cout << "\tCurrent Step: " << (stepCounter + 1) << endl;
    cout << "\tAnt direction: " << dirStr << endl;
    cout << "\tAnt row: " << ant_row << endl;
    cout << "\tAnt column: " << ant_col << endl;
    cout << "\n";

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
    for(stepCounter = 0; stepCounter < steps; stepCounter++)
    {
        if(direction == 'W')
        {
            check_border();
            if(board[ant_row][ant_col] == ' ')
            {
                board[ant_row][ant_col] = '*';
                print_board();
                direction = 'N';
                board[ant_row][ant_col] = '#';
                ant_row--;
            }
            else if(board[ant_row][ant_col] == '#')
            {
                board[ant_row][ant_col] = '*';
                print_board();
                direction = 'S';
                board[ant_row][ant_col] = ' ';
                ant_row++;
            }
        }
        else if(direction == 'N')
        {
            check_border();
            if(board[ant_row][ant_col] == ' ')
            {
                board[ant_row][ant_col] = '*';
                print_board();
                direction = 'E';
                board[ant_row][ant_col] = '#';
                ant_col++;
            }
            else if(board[ant_row][ant_col] == '#')
            {
                board[ant_row][ant_col] = '*';
                print_board();
                direction = 'W';
                board[ant_row][ant_col] = ' ';
                ant_col--;
            }
        }
        else if(direction == 'E')
        {
            check_border();
            if(board[ant_row][ant_col] == ' ')
            {
                board[ant_row][ant_col] = '*';
                print_board();
                direction = 'S';
                board[ant_row][ant_col] = '#';
                ant_row++;
            }
            else if(board[ant_row][ant_col] == '#')
            {
                board[ant_row][ant_col] = '*';
                print_board();
                direction = 'N';
                board[ant_row][ant_col] = ' ';
                ant_row--;
            }
        }
        else if(direction == 'S')
        {
            check_border();
            if(board[ant_row][ant_col] == ' ')
            {
                board[ant_row][ant_col] = '*';
                print_board();
                direction = 'W';
                board[ant_row][ant_col] = '#';
                ant_col--;
            }
            else if(board[ant_row][ant_col] == '#')
            {
                board[ant_row][ant_col] = '*';
                print_board();
                direction = 'E';
                board[ant_row][ant_col] = ' ';
                ant_col++;
            }
        }
    }
}

void Ant::check_border()
{
    if(ant_row == 0)
    {
        ant_row = rows - 2;
    }
    else if(ant_row == rows - 1)
    {
        ant_row = 1;
    }

    if(ant_col == 0)
    {
        ant_col = cols - 2;
    }
    else if(ant_col == cols - 1)
    {
        ant_col = 1;
    }
}

