#pragma once
// File name: FourInARowBoard.h
// Purpose: Board for the four in a row game
// Author(s): Yousef Mostafa, Ahmed nasser
// ID(s): 20220413, 20220045
// Section: S23
// Date: 16/12/2023
// Version: 1.0
#include "BoardGame_Classes.hpp"

class FourInARowBoard : public Board
{
private:
	int maxNoMoves = 42;
public:
	FourInARowBoard();

	virtual bool update_board(int x, int y, char symbol) override;

	virtual bool is_winner() override;

	virtual bool is_draw() override;

	virtual void display_board() override;

	virtual bool game_is_over() override;
};