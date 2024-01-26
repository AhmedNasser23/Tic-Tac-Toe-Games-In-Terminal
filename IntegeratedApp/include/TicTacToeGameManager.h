// File name: TicTacToeGameManager.h
// Purpose: Create Class TicTacToeGameManager And Inheriate From GameManager Class And Write Prototype Of Parameterize Constructor And ruun Function
// Author(s): Yousef Mostafa, Ahmed nasser
// ID(s): 20220413, 20220045
// Section: S23
// Date: 16/12/2023
// Version: 1.0

#pragma once
#include "BoardGame_Classes.hpp"
class TicTacToeGameManager : public GameManager
{
public:
	TicTacToeGameManager(Board* bPtr, Player* playerPtr[2]);
	virtual void run();
};