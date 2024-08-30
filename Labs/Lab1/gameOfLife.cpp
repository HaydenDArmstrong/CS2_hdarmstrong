#include "gameOfLife.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*
Function to clear terminal depending on OS
*/
void clearScreen() {
// use "cls" in windows and "clear" command in Mac and Linux
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

/*
Function to initialize all cells in the board.
Takes in 2D array of pointers and size of array
Should create structs and populate the array
*/
void initCells(Cell* board[][10], int boardSize) {
    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) { //nested for loop to access arrays and initalize the cells
            board[i][j] = new Cell; //
            board[i][j]->x = i;
            board[i][j]->y = j;
            board[i][j]->state = 0;  // Initializing all cells as dead
            board[i][j]->numLiveNeighbors = 0; //initalize the amount of live neighbors to zero
        }
    }
}

/*
Function to read the board from a file
Prompt for the file to read inside of the function
Structure of file should consist of 10 lines of 0 or 1 to indicate cell state
*/
void readBoard(Cell* board[][10], int boardSize) {
    string chosenFile;
    cout << "Enter the filename to read the board: ";
    cin >> chosenFile;

    ifstream file(chosenFile);
    if (file.is_open()) {
        for (int i = 0; i < boardSize; ++i) {
            string line;
            file >> line;
            for (int j = 0; j < boardSize; ++j) {
                board[i][j]->state = line[j] - '0';  // Convert '0'/'1' char to int
            }
        }
        file.close();
    } else {
        cout << "Unable to open file" << endl;
    }
}

/*
Function to print out all cells to cout
*/
void printCells(Cell* board[][10], int boardSize) {
    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) {
            cout << board[i][j]->state;
        }
        cout << endl;
    }
}

/*
Function to count the number of live neighbors for each cell.
Must use the x, y position stored with each cell to determine which neighbors they have
*/
void findNumNeighbors(Cell* board[][10], int boardSize, Cell* curCell) {
    int liveNeighbors = 0; //init liveNeighbors to 0
    int x = curCell->x;
    int y = curCell->y;

    // check all 8 neighbors
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (i == 0 && j == 0) continue;  // Skip the cell itself
            int newX = x + i;
            int newY = y + j;

            if (newX >= 0 && newX < boardSize && newY >= 0 && newY < boardSize) {
                liveNeighbors += board[newX][newY]->state;
            }
        }
    }
    curCell->numLiveNeighbors = liveNeighbors;
}

/*
Function to update each cell's state based on the number of neighbors
Must use following rules:
- Any live cell with fewer than two live neighbors dies (underpopulation).
- Any live cell with two or three live neighbors lives on to the next generation.
- Any live cell with more than three live neighbors dies (overpopulation).
- Any dead cell with exactly three live neighbors becomes a live cell (reproduction).
*/
bool updateCellState(Cell* board[][10], int boardSize) {
    bool updated = false;
    Cell* tempBoard[10][10];

    // Create a temporary board to store the next state
    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) {
            tempBoard[i][j] = new Cell;
            *tempBoard[i][j] = *board[i][j];  // Copy the current state
            findNumNeighbors(board, boardSize, board[i][j]);

            if (board[i][j]->state == 1) {  // Cell is alive
                if (board[i][j]->numLiveNeighbors < 2 || board[i][j]->numLiveNeighbors > 3) {
                    tempBoard[i][j]->state = 0;  // Cell dies
                    updated = true;
                }
            } else {  // Cell is dead
                if (board[i][j]->numLiveNeighbors == 3) {
                    tempBoard[i][j]->state = 1;  // Cell becomes alive
                    updated = true;
                }
            }
        }
    }

    // Update the original board with the new state
    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) {
            *board[i][j] = *tempBoard[i][j];  // Update the board
            delete tempBoard[i][j];  // Clean up temporary board
        }
    }

    if (!updated)
    {
        cout << "No more stages possible. Program will now end." << endl;
    }
    
    return updated;

}
