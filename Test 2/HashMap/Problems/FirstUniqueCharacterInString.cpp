#include <iostream>
#include <unordered_map>
#include <vector>

int firstUniqChar(std::string s) {
    std::unordered_map<char, int> map;

    for (const char c : s) {
        map[c]++;
    }

    for (int i = 0; i < s.size(); i++) {
        if (map[s[i]] == 1) {
            return i;
        }
    }

    return -1;
}

int main()
{
    std::string s = "leetcode";
    std::cout << firstUniqChar(s);
    return 0;
}