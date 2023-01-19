//
//
//

#include "Words.h"

Words::Words() {                            //imports the words.h file
    importWords();
}

string getExePath() {                       //gives the final path
    char result[ MAX_PATH ];
    return string( result, GetModuleFileName( NULL, result, MAX_PATH ) );
}

string getProjectRoot() {                   //finds where the project is located
    string path = getExePath();
    path = path.substr(0, path.find_last_of("\\"));
    path = path.substr(0, path.find_last_of("\\"));
    return path;
}

string getValidWordsFilename() {                //gives the location of the csv file
    string projectRoot = getProjectRoot();
    return projectRoot + "\\valid-words.csv";
}

void Words::importWords() {                     //imports the csv file and checks if it is there
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

string Words::getWord(int i) {                  //gets a word with index i out of the vector
    if (i < words.size()) {
        return words[i];
    }
    else {
        return words[0];
    }
}

set<string> Words::getWords() {                 //return the set of words, so one can check if a word is in this list
    return setWords;
}

string Words::getRandomWord() {                 //chooses a random word from the list
    static random_device rd;
    static mt19937 rng{rd()};
    static std::uniform_int_distribution<int> uid(0,words.size());
    return getWord(uid(rng));
}