#include "BoardGame_Classes.hpp"
#include "FiveByFiveXOBoard.h"
#include "FiveByFiveXOBoardManager.h"
#include "FourInARowBoard.h"
#include "FourInARowGameManager.h"
#include "PyramidTicTacToeBoard.h"
#include "PyramidTicTacToeBoardManager.h"
#include "TicTacToeGameManager.h"
#include <iostream>

int main() {
	cout << "|---------------------------------------------------------------------------------------------------------------------|\n";
	cout << "|----------------------------------------------- Welcome to FCAI Games -----------------------------------------------|\n";
	cout << "|---------------------------------------------------------------------------------------------------------------------|\n";


	int choice1;
	char choice2;
	Player* players[2];
	GameManager* game;

	cout << "1-> FivexFive Tic Tac Toe\n" <<
			"2-> Four In A Row\n" <<
			"3-> Tic Tac Toe (XO)\n" <<
			"4-> Pyramid Tic Tac Toe\n";
	cout << "- Enter The Number Of The Game: ", cin >> choice1;

	while (choice1 < 1 || choice1 > 4) {
		cout << "- Invalid Input!!!, Renter Choice: ", cin >> choice1; cout << '\n';
	}


	cout << "- You Will Play With Computer [y - n]: "; cin >> choice2;

	while (choice2 != 'y' && choice2 != 'n') {
		cout << "- Invalid!!, Renter Choice: ", cin >> choice2;
	}

	players[0] = new Player(1, 'X');

	if (choice2 == 'n') {
		players[1] = new Player(2, 'O');
	}

	switch (choice1) {
	case 1:
		if (choice2 == 'y') players[1] = new RandomPlayer('O', 6);
		game = new FiveByFiveXOBoardManager(new FiveByFiveXOBoard(players[0]->get_symbol(), players[1]->get_symbol()), players);
		game->run();
		system("pause");
		break;

	case 2:
		if (choice2 == 'y') players[1] = new RandomPlayer('O', 8);
		game = new FourInARowGameManager(new FourInARowBoard(), players);
		game->run();
		system("pause");
		break;

	case 3:
		if (choice2 == 'y') players[1] = new RandomPlayer('O', 3);
		game = new TicTacToeGameManager(new X_O_Board(), players);
		game->run();
		system("pause");
		break;

	case 4:
		if (choice2 == 'y') players[1] = new RandomPlayer('O', 5);
		game = new PyramidTicTacToeBoardManager(new PyramidTicTacToeBoard, players);
		game->run();
		system("pause");
		break;
	}

}
