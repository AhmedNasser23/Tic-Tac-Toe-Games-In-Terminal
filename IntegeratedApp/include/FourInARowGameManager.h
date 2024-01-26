#pragma once
// File name: FourInARowGameManager.h
// Purpose: Game Manager for the four in a row game
// Author(s): Yousef Mostafa, Ahmed nasser
// ID(s): 20220413, 20220045
// Section: S23
// Date: 16/12/2023
// Version: 1.0

#include "BoardGame_Classes.hpp"

class FourInARowGameManager : public GameManager
{
public:
	FourInARowGameManager(Board* bPtr, Player* playerPtr[2]);
	virtual void run();
};