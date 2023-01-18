//
// Created by Rogier on 18/01/2023.
//

#include "Game.h"

using namespace std;

Game::Game(string word) {
    this->word = word;
}

Board makeBoard() {
    Board board;
    return board;
}

void Game::fontWordle() {
    cout << "    __          __           _ _       \n";
    cout << "    \\ \\        / /          | | |      \n";
    cout << "     \\ \\  /\\  / /__  _ __ __| | | ___  \n";
    cout << "      \\ \\/  \\/ / _ \\| '__/ _` | |/ _ \\ \n";
    cout << "       \\  /\\  / (_) | | | (_| | |  __/ \n";
    cout << "        \\/  \\/ \\___/|_|  \\__,_|_|\\___| \n";
    cout << "\n";
    cout << "A wordle game in C++, created by Trui en Frans 2023 \n"; //TODO fix names

    cout << board.toString();
}

string Game::getWord() {
    return word;
}