#include <vector>
#include <unordered_map>
#include <iostream>

bool isIsomorphic(std::string s, std::string t) {
    if (s.size() != t.size()) return false;

    std::unordered_map<char, char> sMap;
    std::unordered_map<char, char> tMap;

    for (int i = 0; i < s.size(); i++) {
        if (sMap.find(s[i]) != sMap.end() && sMap[s[i]] != t[i]) return false;
        if (tMap.find(t[i]) != tMap.end() && tMap[t[i]] != s[i]) return false;

        sMap[s[i]] = t[i];
        tMap[t[i]] = s[i];
    }

    return true;
}

int main()
{
    std::string s = "bbbaaaba";
    std::string t = "aaabbbba";
    std::cout << isIsomorphic(s, t);
    return 0;
}