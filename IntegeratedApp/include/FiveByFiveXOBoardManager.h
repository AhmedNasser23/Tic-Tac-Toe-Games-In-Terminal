#pragma once
// File name: FiveByFiveXOBoardManager.h
// Purpose: Game Manager for the 5x5 xo game
// Author(s): Yousef Mostafa
// ID(s): 20220413
// Section: S23
// Date: 16/12/2023
// Version: 1.0
#include "BoardGame_Classes.hpp"

class FiveByFiveXOBoardManager : public GameManager
{
public:
	FiveByFiveXOBoardManager(Board* bPtr, Player* playerPtr[2]);
	virtual void run();
};