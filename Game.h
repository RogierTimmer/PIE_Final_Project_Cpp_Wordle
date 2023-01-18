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
    int turn = 0;

public:
    Game(string word);

    void fontWordle();

    string getWord();

    char* correctingFunction(string guess, string word, char *emptyArray);

    string inputFunction();

    bool checkingInputFunction(string input);

    void play();
};

#endif //FINAL_PROJECT_WORDLE_GAME_H
