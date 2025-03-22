#include <iostream>
#include <unordered_map>
#include <vector>

int firstUniqChar(std::string& s) {
    std::unordered_map<char, int> freq;

    for (auto c: s) freq[c]++;
    
    for (int i = 0; i < s.size(); i++) if (freq[s[i]] == 1) return i;

    return -1;
}

int main()
{
    std::vector<std::string> tests = {"leetcode", "loveleetcode", "aabb"};
    for (auto& s : tests) {
        std::cout << firstUniqChar(s) << std::endl;
    }
    return 0;
}