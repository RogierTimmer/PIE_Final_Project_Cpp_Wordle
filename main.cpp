#include <iostream>
#include <string>
#include "Game.cpp"
#include "Words.cpp"

using namespace std;

int main() {
    Game game;
    game.fontWordle();
    game.play();
    cout << "You guessed correct: " + game.getWord() << "\n";
    return 0;
}
