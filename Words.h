//
// The words class which has all playable words and can return a random word in this list
//

#ifndef FINAL_PROJECT_WORDLE_WORDS_H
#define FINAL_PROJECT_WORDLE_WORDS_H

#include <iostream>
#include <fstream>
#include <vector>
#include <windows.h>
#include <random>
#include <set>

using namespace std;

class Words {
private:
    vector<string> words;       //the list of words in a vector, so we can return a word by its index
    set<string> setWords;       //the set of words, so we can easily check if words are in this set

public:
    Words();                    //imports the words.h file

    void importWords();         //imports the csv file and checks if it is there

    string getWord(int i);      //gets a word with index i out of the vector

    set<string> getWords();     //return the set of words, so one can check if a word is in this list

    string getRandomWord();     //chooses a random word from the list
};

#endif //FINAL_PROJECT_WORDLE_WORDS_H
