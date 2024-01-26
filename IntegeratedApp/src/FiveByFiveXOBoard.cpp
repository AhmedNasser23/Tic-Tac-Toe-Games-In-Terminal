// File name: FiveByFiveXOBoard.cpp
// Purpose: Board for the 5x5 xo game
// Author(s): Yousef Mostafa
// ID(s): 20220413
// Section: S23
// Date: 16/12/2023
// Version: 1.0

#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include "FiveByFiveXOBoard.h"
using namespace std;

FiveByFiveXOBoard::FiveByFiveXOBoard(char first_player_symbol, char second_player_symbol)
{
    n_cols = 5;
    n_rows = 5;

    board = new char* [n_rows];
    for (int i = 0; i < n_rows; i++) {
        board[i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }

	//Creates a player mapping to know which player won
    playerMapping[0] = toupper(first_player_symbol);
    playerMapping[1] = toupper(second_player_symbol);
}

void FiveByFiveXOBoard::update_score(char symbol)
{
	int score = 0;

	int horizontalWin = 0;
	int verticalWin = 0;
	int diagonalLeftWin = 0;
	int diagonalRightWin = 0;

	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			horizontalWin = 0;
			verticalWin = 0;
			diagonalLeftWin = 0;
			diagonalRightWin = 0;

			// Saves the previously pushed combinations
			vector<vector<int>> horizontalArray(3);
			vector<vector<int>> verticalArray(3);
			vector<vector<int>> diagonalArrayLeft(3);
			vector<vector<int>> diagonalArrayRight(3);

			for (int k = -1; k <= 1; ++k)
			{
				if (j + k >= 0 && j + k < n_cols)
				{
					horizontalWin += (board[i][j + k] != 0 && board[i][j + k] == symbol);
					horizontalArray[k + 1].push_back(i);
					horizontalArray[k + 1].push_back(j + k);
				}

				if (i + k >= 0 && i + k < n_rows)
				{
					verticalWin += (board[i + k][j] != 0 && board[i + k][j] == symbol);
					verticalArray[k + 1].push_back(i + k);
					verticalArray[k + 1].push_back(j);
				}

				if (j + k >= 0 && j + k < n_cols && i + k >= 0 && i + k < n_rows)
				{
					diagonalLeftWin += (board[i + k][j + k] != 0 && board[i + k][j + k] == symbol);
					diagonalRightWin += (board[i + k][j + (-k)] && board[i + k][j + (-k)] == symbol);

					diagonalArrayLeft[k + 1].push_back(i + k);
					diagonalArrayLeft[k + 1].push_back(j + k);

					diagonalArrayRight[k + 1].push_back(i + k);
					diagonalArrayRight[k + 1].push_back(j + (-k));
				}
			}

			if (horizontalWin == 3)
			{
				if (find(visited.begin(), visited.end(), horizontalArray) == visited.end())
				{
					score += 1;
					visited.push_back(horizontalArray);
				}
			}

			if (verticalWin == 3)
			{
				if (find(visited.begin(), visited.end(), verticalArray) == visited.end())
				{
					score += 1;
					visited.push_back(verticalArray);
				}
			}

			if (diagonalLeftWin == 3)
			{
				if (find(visited.begin(), visited.end(), diagonalArrayLeft) == visited.end())
				{
					score += 1;
					visited.push_back(diagonalArrayLeft);
				}
			}

			if (diagonalRightWin == 3)
			{
				if (find(visited.begin(), visited.end(), diagonalArrayRight) == visited.end())
				{
					score += 1;
					visited.push_back(diagonalArrayRight);
				}
			}
		}
	}
    
	if (symbol == playerMapping[0])
		first_player_score += score;
	else
		second_player_score += score;
}

bool FiveByFiveXOBoard::update_board(int x, int y, char symbol)
{
	if (x < 0 || x > 4 || y < 0 || y > 4 || board[x][y] != 0)
		return false;

	board[x][y] = toupper(symbol);
	n_moves++;
	update_score(toupper(symbol));

	return true;
}

bool FiveByFiveXOBoard::is_winner()
{
    return (n_moves == max_n_moves) && (first_player_score != second_player_score);
}

bool FiveByFiveXOBoard::is_draw()
{
    return (n_moves == max_n_moves) && !is_winner();
}

void FiveByFiveXOBoard::display_board()
{
    for (int i = 0; i < n_rows; ++i) {
        cout << "\n| ";
        for (int j = 0; j < n_cols; ++j) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << board[i][j] << " |";
        }
        cout << "\n------------------------------------------------";
    }
    cout << endl;
}

bool FiveByFiveXOBoard::game_is_over()
{
    return (n_moves >= max_n_moves || is_winner()) ;
}

char FiveByFiveXOBoard::getWinner()
{
	if (first_player_score > second_player_score)
		return playerMapping[0];
	return playerMapping[1];
}