#pragma once
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
