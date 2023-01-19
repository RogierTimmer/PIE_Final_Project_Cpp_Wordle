//
// Created by Rogier on 18/01/2023.
//

#include "Words.h"

Words::Words() {
    importWords();
}

string getExePath() {
    char result[ MAX_PATH ];
    return string( result, GetModuleFileName( NULL, result, MAX_PATH ) );
}

string getProjectRoot() {
    string path = getExePath();
    path = path.substr(0, path.find_last_of("\\"));
    path = path.substr(0, path.find_last_of("\\"));
    return path;
}

string getValidWordsFilename() {
    string projectRoot = getProjectRoot();
    return projectRoot + "\\valid-words.csv";
}

void Words::importWords() {
    fstream file;

    file.open(getValidWordsFilename());
    string line;

    if (file.fail()) {
        cerr << "Error: " << strerror(errno);
        cout << "ERROR\n";
        return;
    }

    while (!file.eof()) {
        getline(file, line);
        words.push_back(line);
        setWords.insert(line);
    }

    file.close();
}

string Words::getWord(int i) {
    if (i < words.size()) {
        return words[i];
    }
    else {
        return words[0];
    }
}

set<string> Words::getWords() {
    return setWords;
}

string Words::getRandomWord() {
    static random_device rd;
    static mt19937 rng{rd()};
    static std::uniform_int_distribution<int> uid(0,words.size());
    return getWord(uid(rng));
}