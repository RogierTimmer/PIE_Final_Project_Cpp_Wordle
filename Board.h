// Is responsable for the user-interface of the game
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
    int DIM_HOR = 5;
    int DIM_VER = 6;
    string fields[5*6];
    int line = 0;
    char corrections[6*5];

public:
    Board();

    void print();

    void setLine(string guess, char* correction);

    void reset();

};

#endif //FINAL_PROJECT_WORDLE_BOARD_H
