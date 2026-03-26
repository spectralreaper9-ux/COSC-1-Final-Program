//Hangman game that has lives and uses external file to randomly select a word
//Raylib doesn't really work with hangman, would have to use ascii art for hangman
//OR find a different GUI that can display c++ strings
//Alternative option is to make checkers with raylib

#include <iostream>

#include "gameFunctions.h"

int main()
{
    std::string selectedWord = chooseHangmanName();
    std::cout << selectedWord;
}