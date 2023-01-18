//
// Created by Rogier on 18/01/2023.
//

#ifndef FINAL_PROJECT_WORDLE_BOARD_H
#define FINAL_PROJECT_WORDLE_BOARD_H

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Board {
private:
    int DIM_HOR = 5;
    int DIM_VER = 6;
    string fields[5*6];
    int line = 0;

public:
    Board();

    string toString();

    void setLine(string guess);

};

#endif //FINAL_PROJECT_WORDLE_BOARD_H
