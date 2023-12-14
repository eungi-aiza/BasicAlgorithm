#pragma once
#include <string>

// Fill in here
class WordCounter {
    public:
    std::string input_text;
    
    void InputText(std::string);
    int GetWordCount(void);
    int GetCharacterCount(void);
    int GetUniqueWordCount(void);
    int GetWordCount_OneWord(const char *oneWord);
};