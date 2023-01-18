//
// Created by Rogier on 18/01/2023.
//

#ifndef FINAL_PROJECT_WORDLE_WORDS_H
#define FINAL_PROJECT_WORDLE_WORDS_H

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Words {
private:
    vector<string> words;

public:
    Words();

    void importWords();

    string getWord(int i);

    vector<string> getWords();

    string getRandomWord();
};

#endif //FINAL_PROJECT_WORDLE_WORDS_H
