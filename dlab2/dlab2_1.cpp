#include <iostream>
#include <vector>

// String Matching

int patternMatch(std::string& s, std::string& pattern) {
    int res = 0;
    size_t patternPosition = s.find(pattern);

    while (patternPosition != std::string::npos) {
        res++;
        patternPosition = s.find(pattern, patternPosition + 1);
    }

    return res;
}

int main()
{
    std::string s, pattern;
    std::cin >> s >> pattern;
    
    std::cout << patternMatch(s, pattern) << std::endl;

    return 0;
}