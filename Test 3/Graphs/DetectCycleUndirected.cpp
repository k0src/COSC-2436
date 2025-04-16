#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <iostream>
#include <list>

bool hasCycle(const std::unordered_map<std::string, std::list<std::string>>& adj, const std::string& vertex, std::unordered_set<std::string>& visited, const std::string& parent) {
    visited.insert(vertex);

    for (const auto& neighbor : adj.at(vertex)) {
        if (!visited.contains(neighbor)) {
            if (hasCycle(adj, neighbor, visited, vertex)) {
                return true;
            }
        } else if (neighbor != parent) {
            return true;
        }
    }

    return false;
}

bool hasCycle(const std::unordered_map<std::string, std::list<std::string>>& adj) {
    std::unordered_set<std::string> visited;

    for (const auto& [v, _] : adj) {
        if (!visited.contains(v) && hasCycle(adj, v, visited, "")) {
            return true;
        }
    }

    return false;
}

int main() 
{
    std::unordered_map<std::string, std::list<std::string>> adj;

    // Example of UNDIRECTED graph, with cycle at C-B
    adj["A"] = {"B", "C"};
    adj["B"] = {"A", "C", "D"};
    adj["C"] = {"A", "B"};
    adj["D"] = {"B"};

    std::unordered_map<std::string, std::list<std::string>> adj2;

    // Example of UNDIRECTED graph, with NO CYCLE
    adj2["A"] = {"B", "C"};
    adj2["B"] = {"A", "D"};
    adj2["C"] = {"A"};
    adj2["D"] = {"B"};

    std::cout << hasCycle(adj) << std::endl;
    std::cout << hasCycle(adj2) << std::endl;

    return 0;
}