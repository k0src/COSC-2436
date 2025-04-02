#include <iostream>
#include <vector>

std::vector<std::pair<int, int>> directHashing(std::vector<std::pair<int, int>>& input) {
    int max = INT_MIN;
    for (const auto& p : input) {
        if (p.first > max) {
            max = p.first;
        }
    }
    max += 1;
    std::vector<std::pair<int, int>> direct_access_table(max, {-1, -1});
    for (const auto& p : input) {
        if (direct_access_table[p.first].first == -1) {
            direct_access_table[p.first] = p;
        } else {
            std::cout << "Collision at key: " << p.first << std::endl;
        }
    }
    return direct_access_table;
}

int main()
{
    // Key, Value
    std::vector<std::pair<int, int>> input = {{12, 100}, {8, 200}, {4, 300}, {1, 400}, {4, 500}, {5, 600}, {9, 700}, {7, 800}, {14, 900}};
    std::vector<std::pair<int, int>> direct_access_table = directHashing(input);
    std::cout << "Input: " << std::endl;
    for (const auto& p : input) {
        std::cout << "{" << p.first << ", " << p.second << "}" << std::endl;
    }
    std::cout << "Direct Access Table: " << std::endl;
    for (int i = 0; i < direct_access_table.size(); ++i) {
        std::cout << "{" << direct_access_table[i].first << ", " << direct_access_table[i].second << "}" << std::endl;
    }
    return 0;
}