//
// Created by Rogier on 18/01/2023.
//

#ifndef FINAL_PROJECT_WORDLE_GAME_H
#define FINAL_PROJECT_WORDLE_GAME_H

#include "Board.cpp"
#include <iostream>
#include "Words.h"

using namespace std;

class Game {
private:
    Board board;
    string word;
    int turn = 1;
    Words words;

public:
    Game();

    void fontWordle();

    string getWord();

    char* correctingFunction(string guess, string word, char *emptyArray);

    static string inputFunction();

    bool checkingInputFunction(string input);

    bool isWinner(char* correction);

    void play();
};

#endif //FINAL_PROJECT_WORDLE_GAME_H
