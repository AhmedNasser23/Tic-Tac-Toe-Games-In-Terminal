// File name: PyramidTicTacToeBoard.h
// Purpose: Create Class PyramidTicTacToeBoard And Inheriate From Board Class And Write Prototype Of Each Function
// Author(s):  Ahmed nasser
// ID(s):s 20220045
// Section: S23
// Date: 16/12/2023
// Version: 1.0

#include "BoardGame_Classes.hpp"
#pragma once

class PyramidTicTacToeBoard : public Board
{
public:
	PyramidTicTacToeBoard();

	virtual bool update_board(int x, int y, char symbol) override;

	virtual bool is_winner() override;

	virtual bool is_draw() override;

	virtual void display_board() override;

	virtual bool game_is_over() override;

};