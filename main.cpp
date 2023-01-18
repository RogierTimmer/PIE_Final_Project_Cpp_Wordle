#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include "Game.cpp"
#include "Words.cpp"

using namespace std;


string inputFunction() {
    string guess;
    cout << "Guess: ";
    cin >> guess;

    return guess;
}

bool checkingInputFunction(string input) {
    bool check = true;
    input = "ready";                //TODO placeholder


    const int length = input.length();

    if (length != 5) {
        cout << "Not the correct amount of letters \n";
        check = false;
    }

    return check;
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

    cout << "You guessed correct: " + game.getWord() << "\n";
    return 0;
}
