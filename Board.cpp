//
//
//

#include "Board.h"

Board::Board() {                                        //constructor which fills the fields with dots
    for (int i = 0; i < (DIM_HOR*DIM_VER); i++) {
        fields[i] = '.';
    }
}

string Board::toFullColor(char colorChar) {              //converts r/g/y into strings color.hpp understands
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

void Board::print() {                                   //prints the board to the command window with letters in green, red or yellow
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

void Board::setLine(string input, char* correction) {      //when a guess is made, it overwrites the dots with the answer guessed and the correction, so it can be printed
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

void Board::reset() {                                   //resets the board if the user want to play another game
    for (int i = 0; i < (DIM_HOR*DIM_VER); i++) {
        fields[i] = '.';
    }
    line = 0;
    fill_n (corrections, 6*5, 0);
}