//
// Created by Rogier on 18/01/2023.
//

#include "Game.h"

using namespace std;

Game::Game() {
    word = words.getRandomWord();
}

Board makeBoard() {
    Board board;
    return board;
}

void Game::fontWordle() {
    cout << "    __          __           _ _       \n";
    cout << "    \\ \\        / /          | | |      \n";
    cout << "     \\ \\  /\\  / /__  _ __ __| | | ___  \n";
    cout << "      \\ \\/  \\/ / _ \\| '__/ _` | |/ _ \\ \n";
    cout << "       \\  /\\  / (_) | | | (_| | |  __/ \n";
    cout << "        \\/  \\/ \\___/|_|  \\__,_|_|\\___| \n";
    cout << "\n";
    cout << "A wordle game in C++, created by Trui en Frans 2023 \n"; //TODO fix names
}

string Game::getWord() {
    return word;
}

char* Game::correctingFunction(string guess, string word, char *emptyArray) { //function should have as input the guess of the user and the final word.
    string userInput = guess;
    string finalWord = word;

    int length = 5;

    char char_array_userInput[userInput.length()];
    strcpy(char_array_userInput,userInput.c_str());

    char char_array_finalWord[finalWord.length()];
    strcpy(char_array_finalWord,finalWord.c_str());

    char copy_word[finalWord.length()];
    strcpy(copy_word,finalWord.c_str());

    int k;
    char g = 'g';
    char y = 'y';
    char r = 'r';
    char null = '0';

    char* correction = emptyArray;

    for (int  i = 0; i < 5; i++) {
        if (char_array_userInput[i] == char_array_finalWord[i]) { //checks for correct letters on the correct place (green)
            correction[i] = g;
            copy_word[i] = 0;
        }
        k = 0;
        for (int j = 0 ; j < 5; j++) {
            if (char_array_userInput[i] != char_array_finalWord[j]) { //checks for the letters that are not in the word (red)
                k++;
            }
            if (k == 5) {
                correction[i] = r;
            }
        }
    }

    //yellow characters
    for (int  i = 0 ; i < 5; i++) {
        if (correction[i] == 0) {
            for (int j = 0 ; j < 5; j++) {
                if (char_array_userInput[i] == copy_word[j]) {
                    correction[i] = y;
                    copy_word[j] = null;
                    break;
                }
                if (j == 4) {
                    correction[i] = r;
                }
            }
        }
    }
    correction[5] = '\0';
    return correction;
}

string Game::inputFunction() {
    string guess;
    cout << "What is your guess?\n";
    cin >> guess;
    return guess;
}

bool Game::checkingInputFunction(string input) {
    int length = input.length();

    if (length != 5) {
        cout << "Not the correct amount of letters \n";
        return false;
    }

    const bool is_in = words.getWords().count(input) > 0;
    if (!is_in) {
        cout << "Please enter a word that exists \n";
    }
    return is_in;
}

bool Game::isWinner(char* correction) {
    for (int i = 0; i < 5; i++) {
        if (correction[i] != 'g') {
            return false;
        }
    }
    return true;
}

void Game::play() {
    bool run = true;
    board.print();
    while (run) {
        string guess;
        while (true) {
            guess = inputFunction();
            if (checkingInputFunction(guess)) {
                break;
            }
        }
        char emptyArray[6];
        char* corrected = correctingFunction(guess, word, emptyArray);
        for (int i = 0; i < 5; i++) {
            cout << corrected[i];
        }
        board.setLine(guess, corrected);
        board.print();
        if (isWinner(corrected)) {
            cout << "Congratulations, you have guessed the word in " << turn  << " turns!" << "\n";
        }
        turn++;
        if (turn > 5) {
            run = false;
            cout << "Unfortunately you could not guess the word, the word was: " << word << "\n";
        }
    }
}