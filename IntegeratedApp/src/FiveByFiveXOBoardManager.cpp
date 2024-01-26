#include <iostream>
#include "FiveByFiveXOBoardManager.h"

using namespace std;

FiveByFiveXOBoardManager::FiveByFiveXOBoardManager(Board* bPtr, Player* playerPtr[2])
{
    boardPtr = bPtr;
    players[0] = playerPtr[0];
    players[1] = playerPtr[1];
}

void FiveByFiveXOBoardManager::run()
{
    int x, y;

    boardPtr->display_board();

    while (!boardPtr->game_is_over())
    {
        for (int i : {0, 1})
        {
            cout << players[i]->to_string() << endl;
            players[i]->get_move(x, y);
            while (!boardPtr->update_board(x, y, players[i]->get_symbol()))
            {
                players[i]->get_move(x, y);
            }

            boardPtr->display_board();
            if (boardPtr->is_winner())
            {
                // returns a winner based on which sympol is returned from getWinner
                if (toupper(boardPtr->getWinner()) == toupper(players[0]->get_symbol()))
                    cout << "\n---------------------------------------------------\n-> Congratulation: " << players[0]->to_string()
                    << " Is The Winner\n---------------------------------------------------\n-> Hard Luck: " << players[1]->to_string() << "\n---------------------------------------------------\n";
                else
                    cout << "\n---------------------------------------------------\n-> Congratulation: " << players[1]->to_string()
                    << " Is The Winner\n---------------------------------------------------\n-> Hard Luck: " << players[0]->to_string() << "\n---------------------------------------------------\n";

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
