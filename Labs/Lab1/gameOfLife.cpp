#include "gameOfLife.h"

/* board 0: no change 
board 1: pattern then eventual board 0 pattern then exit
board 2: pattern that will never exit */

/*
Function to clear terminal depending on OS
*/
void clearScreen()
{
    // use "cls" in windows and "clear" command in Mac and Linux
    #ifdef _WIN32
        system("clS");
    #else
        system("clear");
    #endif
}

/*
Function to initialize all cells in the board.
Takes in 2D array of pointers and size of array
Should create structs and populate the array
*/


void initCells(Cell* board[][10], int boardSize)
{
    for (int i=0; i < 10; i++) //start at 0 not 1 as to not skip the first column and row (which is zero)
    {
        for (int j=0; j < 10; j++)
        {
        board[i][j] = new Cell(); // Allocate new Cell
        board[i][j]->x = i;
        board[i][j]->y = j;
        board[i][j]->state = 0; // Assuming 0 is dead and 1 is alive
        }

    }
}


/*
Function to read the board from a file 
Prompt for the file to read inside of the function
Structure of file should consist of 10 lines of 0 or 1 to indicate cell state
*/
void readBoard(Cell* board[][10], int boardSize) 
{   
    string chosenFile;
    cout << "Enter the filename to read the board: ";
    cin >> chosenFile;
    
    ifstream fin(chosenFile);
    if (!fin) {
        cerr << "Error opening file!" << endl;
        return;
    }

   /*  while(therearelines)
    {
        getline --> int instr
        create instance of cell
        store char as int in cell.state (reads in as char, need to convert to int (subtract 48 because of ASCII key or char 0)
        store x and y in cell
        store cell address in board[i][j]
    }
 */
    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) {
            int state;
            fin >> state;
            board[i][j]->state = state;
        }
    }

    fin.close();
}




/*
Function to print out all cells to cout
*/
void printCells(Cell* board[][10], int boardSize)
{
    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) {
            cout << (board[i][j]->state ? '1' : '0') << " ";
        }
        cout << endl;
    }
}

/*
Function to count the number of live neighbors for each cell.
Must use the x, y position stored with each cell to determine which neighbors they have
*/
void findNumNeighbors(Cell* board[][10], int boardSize, Cell* curCell, int& liveNeighbors) 
{
    liveNeighbors = 0; //init liveNeighbors to 0
    int x = curCell->x;
    int y = curCell->y;

    // Check all 8 neighbors
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (i == 0 && j == 0) continue; // Skip the cell itself
            int ni = x + i;
            int nj = y + j;
            if (ni >= 0 && ni < boardSize && nj >= 0 && nj < boardSize) {
                liveNeighbors += board[ni][nj]->state;
            }
        }
    }

}

/*
Function to update each cell's state based on number of neighbors
Must use following rules:

Any live cell with fewer than two live neighbors dies, as if by underpopulation.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by overpopulation.
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

Return if you updated cells or not to break out of while loop from main.
*/
bool updateCellState(Cell* board[][10], int boardSize) 
{

    bool updated = false; //when bool updated is called, set to false
    int newStates[10][10]; // Temporary board to store new states

    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) {
            int liveNeighbors;
            findNumNeighbors(board, boardSize, board[i][j], liveNeighbors);

            if (board[i][j]->state == 1) { // Cell is alive
                if (liveNeighbors < 2 || liveNeighbors > 3) {
                    newStates[i][j] = 0; // Cell dies
                    updated = true;
                } else {
                    newStates[i][j] = 1; // Cell survives
                }
            } else { // Cell is dead
                if (liveNeighbors == 3) {
                    newStates[i][j] = 1; // Cell becomes alive
                    updated = true;
                } else {
                    newStates[i][j] = 0; // Cell remains dead
                }
            }
        }
    }

    // Update the board with new states
    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) {
            board[i][j]->state = newStates[i][j];
        }
    }

    return updated;
}


