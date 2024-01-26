// File name: PyramidTicTacToeBoardManager.cpp
// Purpose: Make Implementaion Of Parameterize Constructor And Function run In PyramidTicTacToeBoardManager Class
// Author(s): Ahmed Nasser Ahmed Mohamed
// ID(s): 20220045
// Section: S23
// Date: 12/12/2023
//�Version: 1


#include <iostream>
#include "PyramidTicTacToeBoardManager.h"
using namespace std;

// Make Pointer Of Type Board, And Pointer Of Type Player
PyramidTicTacToeBoardManager::PyramidTicTacToeBoardManager(Board* bPtr, Player* playerPtr[2])
{
    boardPtr = bPtr;
    players[0] = playerPtr[0];
    players[1] = playerPtr[1];
}

// While Number Of Moves Less Than Or Equal Maximum Number Of Moves, Get Move From User And Update Board If The User Enter Valid Input
// And Display After Each Move And Check There Is Exist Winner And If The Board Draw
void PyramidTicTacToeBoardManager::run()

{
    int x, y;

    boardPtr->display_board();

    while (!boardPtr->game_is_over())
    {
        for (int i:{0,1})
        {
            cout << players[i]->to_string();
            players[i]->get_move(x, y);
            while (!boardPtr->update_board (x, y, players[i]->get_symbol()))
            {
                players[i]->get_move(x, y);
            }
            boardPtr->display_board();
            if (boardPtr->is_winner())
            {
                cout  << "\n---------------------------------------------------\n-> Congratulation: " << players[i]->to_string()
                      << " Is The Winner\n---------------------------------------------------\n-> Hard Luck: " << (i == 1 ? players[0]->to_string() : players[1]->to_string()) << "\n---------------------------------------------------\n";
                return;
            }

            if (boardPtr->is_draw())
            {
                cout << "------------------------> The Cells Full!!!, There Isn't Exist Winner ------------------------>\n";
                return;
            }
        }
    }
}