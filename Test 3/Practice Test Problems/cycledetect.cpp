#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <list>

using namespace std;

bool hasCycle(unordered_map<string, list<string>>& g, const string& u, unordered_set<string>& visited, unordered_set<string>& rec_stack) {
    if (rec_stack.contains(u)) return true;
    if (visited.contains(u)) return false;

    visited.insert(u);
    rec_stack.insert(u);

    for (auto& v : g.at(u)) {
        if (hasCycle(g, v, visited, rec_stack)) {
            return true;
        }
    }

    rec_stack.erase(u);
    return false;
}

bool hasCycle(unordered_map<string, list<string>>& g) {
    unordered_set<string> visited;
    unordered_set<string> rec_stack;

    for (const auto& [u, _] : g) {
        if (!visited.contains(u) && hasCycle(g, u, visited, rec_stack)) {
            return true;
        }
    }
    return false;
}

int main()
{
    unordered_map<string, list<string>> g = {
        {"A", {"B", "C"}},
        {"B", {"E"}},
        {"C", {"B", "D"}},
        {"D", {"B", "F"}},
        {"E", {"A"}},
        {"F", {"B", "E"}}
    };

    cout << hasCycle(g);
    return 0;
}