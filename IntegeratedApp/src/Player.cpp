#include<iostream>
#include"BoardGame_Classes.hpp"
using namespace std;

Player::Player(char symbol) {
    this->symbol = symbol;
}

Player::Player(int order, char symbol) {
    cout << "-> Welcome player " << order << '\n';
    cout << "-> Please, Enter your name: ", cin >> name;
    this->symbol = symbol;
}

// Take Position From The User And Check If It's In The Valid Range
void Player::get_move(int& x, int& y) {
    cout << "\n-> Please, Enter your move [x, y] separated by spaces: ", cin >> x >> y;
}

string Player::to_string() {
    return "-> Player: [" + name + "]";
}

char Player::get_symbol() {
    return symbol;
}
