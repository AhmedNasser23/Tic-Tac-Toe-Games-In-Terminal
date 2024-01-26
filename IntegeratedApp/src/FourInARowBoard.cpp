// File name: FourInARowBoard.cpp
// Purpose: Board for the four in a row game
// Author(s): Yousef Mostafa, Ahmed nasser
// ID(s): 20220413, 20220045
// Section: S23
// Date: 16/12/2023
// Version: 1.0

#include "FourInARowBoard.h"
#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>

FourInARowBoard::FourInARowBoard()
{
	n_cols = 7;
	n_rows = 6;

	board = new char* [n_rows];
	for (int i = 0; i < n_rows; i++) {
		board[i] = new char[n_cols];
		for (int j = 0; j < n_cols; j++)
			board[i][j] = 0;
	}
}

bool FourInARowBoard::update_board(int x, int y, char symbol)
{
	if (x < 0 || x >= n_rows || y < 0 || y >= n_cols || board[x][y] != 0)
		return false;

	if (x != n_rows - 1 && board[x + 1][y] == 0)
		return false;

	board[x][y] = toupper(symbol);
	++n_moves;
	return true;
}

bool FourInARowBoard::is_winner()
{
	int horizontalWin = 0;
	int verticalWin = 0;
	int diagonalLeftWin = 0;
	int diagonalRightWin = 0;

	for (int i = 0; i < n_rows; ++i)
	{
		for (int j = 0; j < n_cols; ++j)
		{
			horizontalWin = 0;
			verticalWin = 0;
			diagonalLeftWin = 0;
			diagonalRightWin = 0;

			for (int k = -2; k <= 2; ++k)
			{
				if(j + k >= 0 && j + k < n_cols)
					horizontalWin += (board[i][j + k] != 0 && board[i][j] == board[i][j + k]);

				if (i + k >= 0 && i + k < n_rows)
					verticalWin += (board[i + k][j] != 0 && board[i][j] == board[i + k][j]);

				if (j + k >= 0 && j + k < n_cols && i + k >= 0 && i + k < n_rows)
				{
					diagonalLeftWin += (board[i + k][j + k] != 0 && board[i][j] == board[i + k][j + k]);
					diagonalRightWin += (board[i + k][j + (-k)] != 0 && board[i][j] == board[i + k][j + (-k)]);
				}
			}

			if (horizontalWin >= 4 || verticalWin >= 4 || diagonalLeftWin >= 4 || diagonalRightWin >= 4)
				return true;
		}
	}
	return false;
}

bool FourInARowBoard::is_draw()
{
	return n_moves >= maxNoMoves && !is_winner();
}

void FourInARowBoard::display_board()
{
	for (int i = 0; i < n_rows; ++i) {
		cout << "\n| ";
		for (int j = 0; j < n_cols; ++j) {
			cout << "(" << i << "," << j << ")";
			cout << setw(2) << board[i][j] << " |";
		}
		cout << "\n--------------------------------------------------------";
	}
	cout << endl;
}

bool FourInARowBoard::game_is_over()
{
	return n_moves >= maxNoMoves;
}