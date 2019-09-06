#ifndef ANT.HPP
#define ANT.HPP

class Ant
{
private:
    //variables to hold the dimensions of the board
    int cols;
    int rows;
    //variable to hold the number of steps for the ant to take
    int steps;
    //board is a pointer to a two-dimensional array of pointers
    char** board;
public:
    Ant(int, int, int);
    ~Ant();
    void print_board();
    void run_simulation();
};

#endif
