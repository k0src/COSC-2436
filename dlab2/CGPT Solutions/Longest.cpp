#include <iostream>
#include <algorithm>

int longestConsecutiveChar(const std::string& s) {
    if (s.empty()) return 0;
    
    int max_length = 1, current_length = 1;

    for (size_t i = 1; i < s.size(); i++) {
        if (s[i] == s[i - 1]) {
            current_length++;
        } else {
            max_length = std::max(max_length, current_length);
            current_length = 1;
        }
    }

    return std::max(max_length, current_length);
}

int main()
{
    std::string s;
    std::cin >> s;
    std::cout << longestConsecutiveChar(s);
    return 0;
}