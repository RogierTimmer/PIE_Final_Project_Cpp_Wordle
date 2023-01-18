#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include "source/Game.h"
#include "source/Words.h"

using namespace std;

string inputFunction() {
    string guess;
    cout << "Guess: ";
    cin >> guess;

    return guess;
}

bool checkingInputFunction() {
    string input;
    bool check = true;
    input = "ready";                //TODO placeholder


    const int length = input.length();

    char* char_input = new char[length+1];
    ::strcpy(char_input,input.c_str());

    if (input.length() != 5) {
        cout << "Not the correct amount of letters \n";
        check = false;
    }


    return check;
}

string correctingFunction() { //function should have as input the guess of the user and the final word.
    string userInput = "rally"; //TODO fix that the user-input is actually here
    string finalWord = "ready"; //TODO fix that the final word is actually here

    const int length = userInput.length();

    const char* char_array_userInput = userInput.c_str();

//    char* char_array_userInput = new char[length + 1];
//    strcpy(char_array_userInput,userInput.c_str());

    char* char_array_finalWord = new char[length +1];
    strcpy(char_array_finalWord,finalWord.c_str());

    char* copy_word = new char[length +1];
    strcpy(copy_word,finalWord.c_str());

    char correction[5]; //Array to store the correction scheme

    int k;
    char g = 'g';
    char y = 'y';
    char r = 'r';

    for (int  i = 0 ; i < 5; i++) {
        if (char_array_userInput[i] == char_array_finalWord[i]) { //checks for correct letters on the correct place (green)
            correction[i] = g;
            copy_word[i] = 0;
        }
        cout << correction[0] << correction[5] << " correction point after green \n";
        k = 0;
        for (int j = 0 ; i < 5; i++) {
            if (char_array_finalWord[i]==char_array_userInput[j]) { //checks for the letters that are not in the word (red)

            }
            else{
                k++;
            }
        if (k == 5) {
            correction[i] = r;
            copy_word[i] =0;
            }
        }
    }

    //yellow characters
    for (int  i = 0 ; i < 5; i++) {
        if (!(correction[i] == g && correction[i] == r)) {
            for (int j = 0 ; i < 5; i++) {
                if (char_array_userInput[i] == char_array_finalWord[j]) {
                    correction[i] = y;
                    copy_word[i] = 0;
                }
            }
        }
    }

    cout << "correction " << correction << "\n";
    string s(correction);
    cout << sizeof(correction) / sizeof(char) << correction[1] << "\n";
    return s;
}

void outputFunction() {
    for (int  i = 0 ; i < 6; i++) {

    }
}

void countingFunction() {

}

void revealWordFunction() {

}

int main() {
    Words words;
    Game game(words.getRandomWord());
    game.fontWordle();
    cout << correctingFunction() << "\n";
    cout << "You guessed correct: " + game.getWord() << "\n";
    return 0;
}
