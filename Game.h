//
// Created by Rogier on 18/01/2023.
//

#ifndef FINAL_PROJECT_WORDLE_GAME_H
#define FINAL_PROJECT_WORDLE_GAME_H

#include <iostream>
using namespace std;

#include "Board.cpp"

class Game {
private:
    Board board;
    string word;

public:
    Game(string word);

    void fontWordle();

    string getWord();

    string correctingFunction();
};

#endif //FINAL_PROJECT_WORDLE_GAME_H
