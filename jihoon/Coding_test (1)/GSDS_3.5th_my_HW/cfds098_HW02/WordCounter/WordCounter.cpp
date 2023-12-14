#include "WordCounter.h"
#include <string>
#include <iostream>
#include <map>
#include <set>
using namespace std;

// Fill in here
void WordCounter::InputText(string text) {
    input_text = text;
}

int WordCounter::GetWordCount(void) {
    if (input_text == "") {
        return 0;
    }
    int len = input_text.length();
    int num_words = 0;
    string word = "";
    if ((input_text[0] != ' ') && (input_text[0] != '.') && (input_text[0] != ',')) {
        word += input_text[0];
    }
    for (int i = 1; i < len; i++) {
        if (((input_text[i-1] != ' ') && (input_text[i-1] != '.') && (input_text[i-1] != ',')) && 
        ((input_text[i] == ' ') || (input_text[i] == '.') || (input_text[i] == ','))) {
            num_words++;
            word = "";
        }
        if(((input_text[i] != ' ') && (input_text[i] != '.') && (input_text[i] != ','))) {
            word += input_text[i];
        }
        if ((i == (len-1)) && (word != "")) {
            num_words++;
            word = "";
        }
    }
    return num_words;
    
    /*if (input_text == "") {
        return 0;
    }
    int len = input_text.length();
    int num_words = 0;
    if ((len == 1) && (input_text[0] == ' ')) {
        return 0;
    }
    if ((len == 1) && (input_text[0] != ' ')) {
        return 1;
    }
    for (int i = 1; i < len; i++) {
        if ((input_text[i-1] != ' ') && (input_text[i] == ' ')) {
            num_words++;
        }
    }
    num_words++;
    return num_words;*/
}

int WordCounter::GetCharacterCount(void) {
    if (input_text == "") {
        return 0;
    }
    int len = input_text.length();
    int num_chars = 0;
    for (int i = 0; i < len; i++) {
        if ((input_text[i] != ' ') && (input_text[i] != ',') && (input_text[i] != '.')) {
            num_chars++;
        }
    }
    return num_chars;
}

int WordCounter::GetUniqueWordCount(void) {
    if (input_text == "") {
        return 0;
    }
    set<string> s;
    int len = input_text.length();
    string word = "";
    if ((input_text[0] != ' ') && (input_text[0] != '.') && (input_text[0] != ',')) {
        word += input_text[0];
    }
    for (int i = 1; i < len; i++) {
        if (((input_text[i-1] != ' ') && (input_text[i-1] != '.') && (input_text[i-1] != ',')) && 
        ((input_text[i] == ' ') || (input_text[i] == '.') || (input_text[i] == ','))) {
            s.insert(word);
            word = "";
        }
        if(((input_text[i] != ' ') && (input_text[i] != '.') && (input_text[i] != ','))) {
            word += input_text[i];
        }

        // case for last character since it does not have a space, or '.' or ',' at the end of string.
        if ((i == (len-1)) && (word != "")) {
            s.insert(word);
            word = "";
        }

    }

    return s.size();
}

int WordCounter::GetWordCount_OneWord(const char *oneWord) {
    if (input_text == "") {
        return 0;
    }
    // 1. Create a hash map that contains the occurence of each word.
    map<string, int> dict;
    int len = input_text.length();
    string word = "";
    if ((input_text[0] != ' ') && (input_text[0] != '.') && (input_text[0] != ',')) {
        word += input_text[0];
    }
    for (int i = 1; i < len; i++) {
        if (((input_text[i-1] != ' ') && (input_text[i-1] != '.') && (input_text[i-1] != ',')) && 
        ((input_text[i] == ' ') || (input_text[i] == '.') || (input_text[i] == ','))) {
            if (dict.count(word) == 0) {
                dict[word] = 1;
            }
            else {
                dict[word]++;
            }
            word = "";
        }
        if(((input_text[i] != ' ') && (input_text[i] != '.') && (input_text[i] != ','))) {
            word += input_text[i];
        }
        if ((i == (len-1)) && (word != "")) {
            dict[word]++;
        }
    }

    // 2. Find the key of oneWord and fetch the value of it.
    return dict[oneWord];
}