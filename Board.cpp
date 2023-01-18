//
// Created by Rogier on 18/01/2023.
//

#include "Board.h"

Board::Board() {
    for (int i = 0; i < (DIM_HOR*DIM_VER); i++) {
        fields[i] = ".";
    }
}

string Board::toString() {
    string s;
    s += "+---+---+---+---+---+\n";
    for (int i = 0; i < DIM_VER; i++) {
        for (int j = 0; j < DIM_HOR; j++) {
            s += "| " + fields[i * (DIM_HOR) + j] + " ";
        }
        s += "|\n";
        s += "+---+---+---+---+---+\n";
    }
    return s;
}