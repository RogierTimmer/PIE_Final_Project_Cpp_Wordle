# PIE_Final_Project_Cpp_Wordle
This is the repository for the final project of PIE at the University of Twente. In this project a wordle game is made in C++

# Install
In order to install this program, build it using cmake and run it

# Usage
When started up, the game outputs an empty board where the user input will be located once checked.
The player enters its try (a five-letter word) and the program will check if the word is valid.
After this the word will be checked and filled in, in the bord, it will display the words in color, using red for letters...
that are not in the final word, yellow for letters that are in the word, but not in the right place and green for letters...
that are in the correct spot.
The player has five tries to guess the final word, if after the five tries, the word is not guessed correctly, the player loses...
and the game can be played again.

# Adapting the code
The code can be adapted by eg. modifying the valid-words.csv file, in order to get another language. With a bit more work,
the game can be adapted to support 6, 7 or more letter words. Another improvement can be a list with words that are valid for...
final outcome words and a list for words that are valid as input-words.

# Dependencies
The code relies on color.hpp in order to make the colored text in the terminal. Furthermore standard libraries included with...
C++ were used like vector and iostream.

# Final note
This game is based on the popular game wordle (https://www.nytimes.com/games/wordle/index.html) by Josh Wardle. We as...
house mates used to play this everyday, thus the inspiration for this final project.
A special thanks to our housemate Olte, who helped us a during the debugging and finalising of the project.