#include<iostream>
#include"BoardGame_Classes.hpp"
using namespace std;

RandomPlayer::RandomPlayer(char input, int dimension) :Player(input)
{
    this->dimension = dimension;
    this->name = "Random Computer Player";
    cout << "-> My names is " << name << endl;
}

// Return Two Random Number In Range [0 - Diemension -1]
void RandomPlayer::get_move(int& x, int& y) {
    x = (int)(rand() / (RAND_MAX + 1.0) * dimension);
    y = (int)(rand() / (RAND_MAX + 1.0) * dimension);
}
