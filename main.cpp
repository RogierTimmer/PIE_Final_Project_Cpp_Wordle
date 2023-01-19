#include <iostream>
#include <string>
#include "Game.cpp"
#include "Words.cpp"

using namespace std;

bool developMode = false;

int main() {
    Game game;                              //create an instance of the Game class
    game.fontWordle();                      //prints the welcome screen
    while (true) {                          //while the users wants to keep playing
        game.play(developMode);             //run the play command
        string userInput = "?";
        cout << "Do you want to play another game?\n";                  //ask the user if he wants to play again
        while (userInput != "y" && userInput != "n") {                  //if the user does not fill in y or n
            cout << "Please fill in 'y' for yes and 'n' for no.\n";
            cin >> userInput;
        }
        if (userInput == "n") {             //if the does not want to play another game exit the program
            return 0;
        }
    }
}
