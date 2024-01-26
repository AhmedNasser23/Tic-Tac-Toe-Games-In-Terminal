#pragma once
#include "BoardGame_Classes.hpp"

class PyramidTicTacToeBoardManager : public GameManager
{
public:
	PyramidTicTacToeBoardManager(Board* bPtr, Player* playerPtr[2]);
	virtual void run();
};
