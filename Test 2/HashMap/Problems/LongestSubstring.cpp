#include <iostream>
#include <unordered_map>

int lengthOfLongestSubstring(std::string s) {
    std::unordered_map<char, int> indices;

    int j = 0;
    int max_len = 0;

    for (int i = 0; i < s.size(); i++) {
        if (indices.find(s[i]) != indices.end()) {
            j = std::max(j, indices[s[i]] + 1);
        }

        indices[s[i]] = i;

        max_len = std::max(i - j + 1, max_len);
    }

    return max_len;
}

int main()
{
    std::string s = "abcabcbb";
    std::cout << lengthOfLongestSubstring(s);

    return 0;
}