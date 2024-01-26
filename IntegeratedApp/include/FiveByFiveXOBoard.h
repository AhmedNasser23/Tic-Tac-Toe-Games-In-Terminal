#pragma once
// File name: FiveByFiveXOBoard.h
// Purpose: Board for the 5x5 xo game
// Author(s): Yousef Mostafa
// ID(s): 20220413
// Section: S23
// Date: 16/12/2023
// Version: 1.0

#include "BoardGame_Classes.hpp"
#include <vector>

class FiveByFiveXOBoard : public Board
{
private:
	int max_n_moves = 24;
	char playerMapping[2];
	vector<vector<vector<int>>> visited;
	int first_player_score = 0;
	int second_player_score = 0;

public:
	FiveByFiveXOBoard(char symbol, char second_player_symbol);

	void update_score(char symbol);

	virtual bool update_board(int x, int y, char _symbol) override;

	virtual bool is_winner() override;

	virtual bool is_draw() override;

	virtual void display_board() override;

	virtual bool game_is_over() override;

	virtual char getWinner() override;

};