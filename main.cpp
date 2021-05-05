//
// Created by cameron on 5/5/21.
//

#include <iostream>
#include "depend/hunspell/src/hunspell/hunspell.hxx"

bool IsSmashable(Hunspell& dictionary, const std::string& inputWord)
{
    bool isInputWordValid = dictionary.spell(inputWord);
    if (isInputWordValid)
    {
        if (inputWord.size() == 1)
        {
            return true;
        }
    }
    else
    {
        return false;
    }

    size_t i = 0;
    std::string newWord = inputWord;
    while (newWord.size() > 1)
    {
        newWord.erase(i++, 1);
        bool isInDictionary = dictionary.spell(newWord);
        if (isInDictionary)
        {
            if (IsSmashable(dictionary, newWord))
            {
                return true;
            }
        }
        else
        {
            newWord = inputWord;
            continue;
        }
    }

    return false;
}

int main(int argc, char** argv)
{
    // TODO add pulling of dictionary to build

    // Setup the dictionary object
    const char* affPath = "en_US.aff";
    const char* dpath = "en_US.dic";
    Hunspell dictionary(affPath, dpath);

    // Allow the user to input the word of interest
    std::cout << "Enter a word to determine if it is smashable" << std::endl;
    std::string inputWord;
    std::cin >> inputWord;

    bool isSmashable = IsSmashable(dictionary, inputWord);

    if (isSmashable)
    {
        std::cout << inputWord << " is smashable" << std::endl;
    }
    else
    {
        std::cout << inputWord << " is not smashable" << std::endl;
    }

    return 0;
}