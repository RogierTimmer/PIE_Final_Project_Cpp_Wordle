#include <iostream>
#include <string>
#include "Game.cpp"
#include "Words.cpp"

using namespace std;

int main() {
    Game game;
    game.fontWordle();
    while (true) {
        game.play();
        string userInput = "?";
        cout << "Do you want to play another game?\n";
        while (userInput != "y" && userInput != "n") {
            cout << "Please fill in 'y' for yes and 'n' for no.\n";
            cin >> userInput;
        }
        if (userInput == "n") {
            return 0;
        }
    }
}
