#include <iostream>
#include <string>
#include "gameOfLife.h"

using namespace std;

void cleanupCells(Cell* board[][10], int boardSize) 
{
    for (int i = 0; i < boardSize; ++i) //nested for loop to access array and delete the cells
    {
        for (int j = 0; j < boardSize; ++j) 
        {
            delete board[i][j];
        }
    };

   // cout << "Cells cleaned" << endl;
}


int main(int argc, char* argv[])
{
    int stage = 0;
    bool boardChanged = true;
    size_t boardSize = 10;
    Cell* board[10][10];

    initCells(board, boardSize);
    //cout << "Cells init" << endl;
    readBoard(board, boardSize);

    while(boardChanged) {
        clearScreen();
        cout << "Stage: " << stage << endl;

        printCells(board, boardSize);
        boardChanged = updateCellState(board, boardSize);

        cin.get();
        stage++;
    }

    //cout << "Cleaning cells..." << endl;

    // Clean up board if cells were allocated on the heap
    cleanupCells(board,boardSize);

   // cout << "Program Finished." << endl;;

    return 0;
}