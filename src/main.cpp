#include <iostream>
#include <fstream>

using namespace std;

string wordChoosingFunction() {
    fstream fin;

    //import the csv file containing the words
    fin.open("valid-words.csv", ios::in);

    //ask for specific word in index
    int wordNumber;
    cout << "Index number of the word? \n";
    cin >> wordNumber;

    //TODO add the choosing of the word in the wordslist
    return "ready";

};

void inputFunction() {

}

void checkingInputFunction() {

}

void correctingFunction() {

}

void outputFunction() {

}

void countingFunction() {

}

void revealWordFunction() {

}

void fontWordle() {


    cout << "    __          __           _ _       \n";
    cout << "    \\ \\        / /          | | |      \n";
    cout << "     \\ \\  /\\  / /__  _ __ __| | | ___  \n";
    cout << "      \\ \\/  \\/ / _ \\| '__/ _` | |/ _ \\ \n";
    cout << "       \\  /\\  / (_) | | | (_| | |  __/ \n";
    cout << "        \\/  \\/ \\___/|_|  \\__,_|_|\\___| \n";
    cout << "\n";
    cout << "A wordle game in C++, created by Trui en Frans 2022 \n"; //TODO fix names


}

int main() {
    int i =3;
    cout << "Hello, Wordle \n";
    fontWordle();
    string finalWord = wordChoosingFunction();
    cout << "Final word is: " << finalWord << " \n"; //TODO remove when finished


    return 0;
}

#pragma clang diagnostic pop