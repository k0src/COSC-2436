#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

void reverseEdges(unordered_map<string, list<pair<string, string>>>& graph) {
    for (auto& [_, edges] : graph) {
        for (auto& [u, v] : edges) {
            std::swap(u, v);
        }
    }
}

int main()
{
    unordered_map<string, list<pair<string, string>>> graph = {
        {"A", {{"B", "C"}, {"D", "E"}}},
        {"B", {{"F", "G"}, {"H", "I"}}},
        {"C", {{"J", "K"}, {"L", "M"}}},
        {"D", {{"N", "O"}, {"P", "Q"}}},
        {"E", {{"R", "S"}, {"T", "U"}}}
    };

    reverseEdges(graph);

    for (const auto& [v, edges] : graph) {
        std::cout << v << ": ";
        for (const auto& [u, v] : edges) {
            std::cout << u << "->" << v << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}