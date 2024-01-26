#pragma once
#include "BoardGame_Classes.hpp"
class TicTacToeGameManager : public GameManager
{
public:
	TicTacToeGameManager(Board* bPtr, Player* playerPtr[2]);
	virtual void run();
};
