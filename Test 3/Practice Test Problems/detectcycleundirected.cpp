#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <list>

using namespace std;

bool hasCycle(unordered_map<string, list<string>>& g, const string& u, unordered_set<string>& visited, const string& parent) {
    visited.insert(u);

    for (const auto& v : g.at(u)) {
        if (!visited.contains(v)) {
            if (hasCycle(g, v, visited, u)) {
                return true;
            }
        } else if (v != parent) {
            return true;
        }
    }

    return false;
}

bool hasCycle(unordered_map<string, list<string>>& g) {
    unordered_set<string> visited;

    for (auto& [u, _] : g) {
        if (!visited.contains(u) && hasCycle(g, u, visited, "")) {
            return true;
        }
    }

    return false;
}

int main()
{
    unordered_map<string, list<string>> g = {
        {"A", {"B", "C"}},
        {"B", {"A"}},
        {"C", {"A"}}
    };

    cout << hasCycle(g);

    return 0;
}