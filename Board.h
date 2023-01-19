// Is responsible for the user-interface of the board part of the game
// Created by Rogier on 18/01/2023.
//

#ifndef FINAL_PROJECT_WORDLE_BOARD_H
#define FINAL_PROJECT_WORDLE_BOARD_H

#include <iostream>
#include <vector>
#include <cstring>
#include "color.hpp"

using namespace std;

class Board {
private:
    int DIM_HOR = 5;                //dimension of the board
    int DIM_VER = 6;
    string fields[5*6];             //fields for a 6*5 game board
    int line = 0;                   //keeping track of how many lines have been written to the board
    char corrections[6*5];          //keeping track of the colors of the letters

public:
    Board();                                        //constructor which fills the fields with dots

    string toFullColor(char colorChar);             //converts r/g/y into strings color.hpp understands

    void print();                                   //prints the board to the command window with letters in green, red or yellow

    void setLine(string guess, char* correction);   //when a guess is made, it overwrites the dots with the answer guessed and the correction, so it can be printed

    void reset();                                   //resets the board if the user want to play another game

};

#endif //FINAL_PROJECT_WORDLE_BOARD_H
