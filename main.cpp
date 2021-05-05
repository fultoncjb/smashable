//
// Created by cameron on 5/5/21.
//

#include <iostream>
#include "depend/hunspell/src/hunspell/hunspell.hxx"

int main(int argc, char** argv)
{
    // TODO add pulling of dictionary to build
    const char* affPath = "en_US.aff";
    const char* dpath = "en_US.dic";
    Hunspell dictionary(affPath, dpath);

    std::string inputWord("duckl");

    bool isWord = dictionary.spell(inputWord);

    if (isWord)
    {
        std::cout << inputWord << " is a word" << std::endl;
    }
    else
    {
        std::cout << inputWord << " is not a word" << std::endl;
    }

    return 0;
}