#include <vector>
#include <unordered_map>
#include <iostream>
#include <sstream>

bool wordPattern(std::string& pattern, std::string& s) {
    std::vector<std::string> words;
    std::istringstream ss(s);

    std::string word;
    while (ss >> word) {
        words.push_back(word);
    }

    std::unordered_map<char, std::string> charToString;
    std::unordered_map<std::string, char> stringToChar;

    for (int i = 0; i < pattern.size(); i++) {
        char c = pattern[i];
        std::string w = words[i];

        if (charToString.count(c)) {
            if (charToString[c] != w) return false;
        } else if (stringToChar.count(w)) {
            if (stringToChar[w] != c) return false;
        } else {
            charToString[c] = w;
            stringToChar[w] = c;
        }
    }

    return true;
}

int main()
{
    std::string pattern = "abba";
    std::string s = "dog cat cat dog";
    std::cout << wordPattern(pattern, s);
    return 0;
}