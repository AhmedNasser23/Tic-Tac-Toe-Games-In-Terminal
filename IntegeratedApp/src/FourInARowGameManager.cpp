// File name: FourInARowGameManager.cpp
// Purpose: Game Manager for the four in a row game
// Author(s): Yousef Mostafa, Ahmed Nasser
// ID(s): 20220413
// Section: S23
// Date: 16/12/2023
// Version: 1.0

#include "FourInARowGameManager.h"
#include "iostream"

FourInARowGameManager::FourInARowGameManager(Board* bPtr, Player* playerPtr[2])
{
    boardPtr = bPtr;
    players[0] = playerPtr[0];
    players[1] = playerPtr[1];
}

void FourInARowGameManager::run()
{
    int x, y;

    boardPtr->display_board();

    while (!boardPtr->game_is_over()) {
        for (int i : {0, 1}) {
            cout << players[i]->to_string() << endl;
            players[i]->get_move(x, y);
            while (!boardPtr->update_board(x, y, players[i]->get_symbol())) {
                players[i]->get_move(x, y);
            }
            boardPtr->display_board();
            if (boardPtr->is_winner()) {
                cout  << "\n---------------------------------------------------\n-> Congratulation: " << players[i]->to_string()
                      << " Is The Winner\n---------------------------------------------------\n-> Hard Luck: " << (i == 1 ? players[0]->to_string() : players[1]->to_string()) << "\n---------------------------------------------------\n";
                return;
            }
            if (boardPtr->is_draw()) {
                cout << "------------------------> The Cells Full!!!, There Isn't Exist Winner ------------------------>\n";
                return;
            }
        }
    }
}