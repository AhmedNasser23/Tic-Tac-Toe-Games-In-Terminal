#pragma once
#include "BoardGame_Classes.hpp"

class FiveByFiveXOBoardManager : public GameManager
{
public:
	FiveByFiveXOBoardManager(Board* bPtr, Player* playerPtr[2]);
	virtual void run();
};
