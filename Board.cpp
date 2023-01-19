//
// Created by Rogier on 18/01/2023.
//

#include "Board.h"

Board::Board() {
    for (int i = 0; i < (DIM_HOR*DIM_VER); i++) {
        fields[i] = ".";
    }
}

string toFullColor(char colorChar) {
    if (colorChar == 'y') {
        return "yellow";
    }
    else if (colorChar == 'g') {
        return "green";
    }
    else if (colorChar == 'r') {
        return "red";
    }
    return "white";
}

void Board::print() {
    string s;
    cout << "+---+---+---+---+---+\n";
    for (int i = 0; i < DIM_VER; i++) {
        for (int j = 0; j < DIM_HOR; j++) {
            cout << "| ";

            string fullColor = toFullColor(corrections[i * (DIM_HOR) + j]);
            cout << dye::colorize(fields[i * (DIM_HOR) + j], fullColor);

            cout << " ";
        }
        cout << "|\n";
        cout <<  "+---+---+---+---+---+\n";
    }
}

void Board::setLine(string input, char* correction) {
    char charArray[input.length()];
    strcpy(charArray,input.c_str());

    for (int i = 0; i < DIM_HOR; i++) {
        corrections[line * (DIM_HOR) + i] = correction[i];
    }
    for(int i=0 ; i<input.length() ; i++) {
        fields[line * (DIM_HOR) + i] = charArray[i];
    }

    line++;
}