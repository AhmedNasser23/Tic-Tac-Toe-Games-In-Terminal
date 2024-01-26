// File name: PyramidTTTBoard.cpp
// Purpose: Make Implementaion Of Parameterize Constructor And Each Function In PyramidTicTacToeBoard Class
// Author(s): Ahmed Nasser Ahmed Mohamed
// ID(s): 20220045
// Section: S23
// Date: 12/12/2023
// Version: 1

#include "BoardGame_Classes.hpp"
#include "PyramidTicTacToeBoard.h"
#include <iostream>
#include <iomanip>

// Make Board Of Size 3x5 And Initialize All Cell Equal '0'
PyramidTicTacToeBoard::PyramidTicTacToeBoard() {
    n_rows = 3,  n_cols = 5;
    board = new char* [n_rows];
    for (int i = 0; i < n_rows; i++) {
        board[i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            if (   (i == 0 && j == 2) || (i == 1 && j == 1)
                || (i == 1 && j == 2) || (i == 1 && j == 3)
                || (i == 2 && j == 0) || (i == 2 && j == 1)
                || (i == 2 && j == 2) || (i == 2 && j == 3)
                || (i == 2 && j == 4)
                ) board[i][j] = '0';
    }
}

// Check If The Position Is Valid And The Cell Has '0' Character To Update Board
bool PyramidTicTacToeBoard::update_board(int x, int y, char symbol) {
    if ((x == 0 && y == 2) || (x == 1 && y == 1) || (x == 1 && y == 2) || (x == 1 && y == 3) || (x == 2 && y == 0) || (x == 2 && y == 1) || (x == 2 && y == 2) || (x == 2 && y == 3) || (x == 2 && y == 4)) {

        if (board[x][y] == '0') {
            board[x][y] = toupper(symbol);
            n_moves++;
            return true;
        }

        else return false;

    }
    else 
        return false;

}

// Check All Possible Winning Combinations And Return True If It Finds All Of Them In The Board
bool PyramidTicTacToeBoard::is_winner() {
    if (  ((board[0][2] == board[1][3] && board[0][2] == board[2][4] && board[1][3] == board[2][4]) && (board[0][2] != '0' && board[1][3] != '0' && board[2][4] != '0'))
        ||((board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[1][1] == board[2][0]) && (board[0][2] != '0' && board[1][1] != '0' && board[2][0] != '0'))
        ||((board[1][1] == board[1][2] && board[1][1] == board[1][3] && board[1][2] == board[1][3]) && (board[1][1] != '0' && board[1][2] != '0' && board[1][3] != '0'))
        ||((board[2][0] == board[2][1] && board[2][0] == board[2][2] && board[2][1] == board[2][2]) && (board[2][0] != '0' && board[2][1] != '0' && board[2][2] != '0'))
        ||((board[2][1] == board[2][2] && board[2][1] == board[2][3] && board[2][2] == board[2][3]) && (board[2][1] != '0' && board[2][2] != '0' && board[2][3] != '0'))
        ||((board[2][2] == board[2][3] && board[2][2] == board[2][4] && board[2][3] == board[2][4]) && (board[2][2] != '0' && board[2][3] != '0' && board[2][4] != '0'))
        ||((board[0][2] == board[1][2] && board[0][2] == board[2][2] && board[1][2] == board[2][2]) && (board[0][2] != '0' && board[1][2] != '0' && board[2][2] != '0'))
        )
        return true;
    else return false;
}

// Check If The Number Of Moves Equal The Number Of Maximum Number Of Moves And There Isn't Exist Winner
bool PyramidTicTacToeBoard::is_draw() {
    if (n_moves == 9 && !is_winner()) return true;
    else return false;
}

// Loop For All Cell In The Vaild Range And Print The Position And The Value Of Charcter In It
void PyramidTicTacToeBoard::display_board() {
    cout << endl << endl;
    for (int i = 0; i < n_rows; i++) {
        cout << "| ";
        if (i == 0)  cout << "------------------- ";
        else if (i == 1) cout << "--------- ";
        for (int j = 0; j < n_cols; j++) {
            if ((i == 0 && j == 2) || (i == 1 && j == 1)
                || (i == 1 && j == 2) || (i == 1 && j == 3)
                || (i == 2 && j == 0) || (i == 2 && j == 1)
                || (i == 2 && j == 2) || (i == 2 && j == 3)
                || (i == 2 && j == 4)
                )
                cout << "(" << i << "," << j << ")" << setw(2) << "[" <<  board[i][j] << "] ";
        }
        if (i == 0) cout << "------------------- |";
        else if (i == 1) cout << "--------- |";
        else if (i == 2) cout << "|";
        cout << "\n";
    }
}

// Return True If The Number Of Moves Greater Than Or Equal The Maximum Number Of Moves
bool PyramidTicTacToeBoard::game_is_over() {
    return n_moves >= 9;
}
