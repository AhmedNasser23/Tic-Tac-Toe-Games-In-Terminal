#pragma once
#include "BoardGame_Classes.hpp"

class FourInARowGameManager : public GameManager
{
public:
	FourInARowGameManager(Board* bPtr, Player* playerPtr[2]);
	virtual void run();
};
