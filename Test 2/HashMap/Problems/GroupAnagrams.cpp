#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
    std::unordered_map<std::string, std::vector<std::string>> map;
    std::vector<std::vector<std::string>> res;

    for (auto s : strs) {
        std::string sorted = s;
        std::sort(sorted.begin(), sorted.end());
        map[sorted].push_back(s);
    }

    for (const auto& p : map) {
        res.push_back(p.second);
    }

    return res;
}

int main()
{
    std::vector<std::string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

    for (const auto& v : groupAnagrams(strs)) {
        for (const auto& s : v) {
            std::cout << s << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}