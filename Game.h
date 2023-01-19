//
// Created by Rogier on 18/01/2023.
// Is making sure that a game can be played from starting up to winning of a game

#ifndef FINAL_PROJECT_WORDLE_GAME_H
#define FINAL_PROJECT_WORDLE_GAME_H

#include "Board.cpp"
#include <iostream>
#include "Words.h"
#include <set>

using namespace std;

class Game {
private:
    Board board;                            //the board instance
    string word;                            //the word that needs to be guessed
    int turn = 1;                           //keeps track of the turn the user is on
    int maxTurn = 6;                        //the maximum turn the user can be on
    Words words;                            //the words instance where the words are chosen from and guesses are checked against
    string guess;                           //the guess of the user(changes every turn)
    set<string> usedWords = {"aaaaa"};      //the set of used words so no double words are chosen


public:
    void fontWordle();                  //makes introduction font

    string getWord();                   //return the word of the current game

    void setWord();                     //sets the word of a game and keeps track of which words have already been chosen

    char* correctingFunction(string guess, char *emptyArray);   //function corrects the input of the user by creating array correction that holds g/r/y

    static string inputFunction();      //is used for the user-input and returns the guess

    bool checkingInputFunction(string input);                   //checks the input function and returns if it is valid

    bool isWinner(char* correction);    //checks when the game is won

    void play(bool developMode);                        //initialises the game
};

#endif //FINAL_PROJECT_WORDLE_GAME_H
