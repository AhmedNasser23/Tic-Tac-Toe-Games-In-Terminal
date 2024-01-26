// File name: PyramidTicTacToeBoardManager.h
// Purpose: Create Class PyramidTicTacToeBoardManager And Inheriate From GameManager Class And Wirte Prototype Of Parameterize Constructor And run Functio
// Author(s): Ahmed nasser
// ID(s): 20220045
// Section: S23
// Date: 16/12/2023
// Version: 1.0

#pragma once
#include "BoardGame_Classes.hpp"

class PyramidTicTacToeBoardManager : public GameManager
{
public:
	PyramidTicTacToeBoardManager(Board* bPtr, Player* playerPtr[2]);
	virtual void run();
};