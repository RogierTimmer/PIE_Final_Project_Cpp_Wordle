//
//
//

#include "Game.h"

using namespace std;

void Game::fontWordle() {                                   //makes introduction font
    cout << "    __          __           _ _       \n";
    cout << "    \\ \\        / /          | | |      \n";
    cout << "     \\ \\  /\\  / /__  _ __ __| | | ___  \n";
    cout << "      \\ \\/  \\/ / _ \\| '__/ _` | |/ _ \\ \n";
    cout << "       \\  /\\  / (_) | | | (_| | |  __/ \n";
    cout << "        \\/  \\/ \\___/|_|  \\__,_|_|\\___| \n";
    cout << "\n";
    cout << "A wordle game in C++, created by Trui en Frans 2023 \n";
}

void Game::setWord() {                                      //sets the word of a game and keeps track of which words have already been chosen
    string attempt = "aaaaa";
    while(const bool is_in = usedWords.count(attempt) > 0) {
        attempt = words.getRandomWord();
    }
    word = attempt;
    usedWords.insert(word);
}

char* Game::correctingFunction(string guess, char *emptyArray) { //function corrects the input of the user by creating array correction that holds g/r/y
    string userInput = guess;

    int length = 5;

    char char_array_userInput[userInput.length()];                              //makes a character array from a string
    strcpy(char_array_userInput,userInput.c_str());

    char char_array_finalWord[word.length()];
    strcpy(char_array_finalWord,word.c_str());

    char copy_word[word.length()];
    strcpy(copy_word,word.c_str());                              //is used for knowing what characters are used

    char g = 'g';
    char y = 'y';
    char r = 'r';
    char null = '0';

    char* correction = emptyArray;

    for (int  i = 0; i < 5; i++) {
        if (char_array_userInput[i] == char_array_finalWord[i]) { //checks for correct letters on the correct place (green)
            correction[i] = g;
            copy_word[i] = null;
        }
        int k = 0;
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
                    copy_word[j] = '&';
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

string Game::inputFunction() {                                      //is used for the user-input and returns the guess
    string guess;
    cout << "What is your guess?\n";
    cin >> guess;
    return guess;
}

bool Game::checkingInputFunction(string input) {                    //checks the input function and returns if it is valid
    int length = input.length();

    if (length != 5) {                                              //checks for number of letters
        cout << "Not the correct amount of letters \n";
        return false;
    }

    const bool is_in = words.getWords().count(input) > 0;         //checks if the word is in the list
    if (!is_in) {
        cout << "Please enter a word that exists \n";
    }
    return is_in;
}

bool Game::isWinner(char* correction) {                             //checks when the game is won
    for (int i = 0; i < 5; i++) {
        if (correction[i] != 'g') {
            return false;
        }
    }
    return true;
}

void Game::play(bool developMode) {                                                 //initialises the game
    setWord();
    if (developMode) {
        cout << word << "\n";
    }
    board.print();
    while (turn <= maxTurn) {
        guess = "aaaaa";
        while (true) {
            guess = inputFunction();
            if (checkingInputFunction(guess)) {
                break;
            }
        }
        char emptyArray[6] = {0,0,0,0,0,'\0'};
        char* corrected = correctingFunction(guess, emptyArray);
        board.setLine(guess, corrected);
        board.print();
        if (isWinner(corrected)) {
            cout << "Congratulations, you have guessed the word in " << turn  << " turns!" << "\n";
            return;
        }
        turn++;
    }
    if (turn >= 6) {
        cout << "Unfortunately you could not guess the word, the word was: " << word << "\n";
    }
    board.reset();
    turn = 1;
}