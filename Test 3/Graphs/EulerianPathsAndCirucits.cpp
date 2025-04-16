#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <iostream>
#include <list>
#include <algorithm>

void dfs(const std::string& u, std::unordered_map<std::string, std::list<std::string>>& adj, std::vector<std::string>& circuit) {
    while (!adj[u].empty()) {
        std::string v = adj[u].front();
        adj[u].pop_front();
        dfs(v, adj, circuit);
    }

    circuit.push_back(u);
}

std::vector<std::string> eulerianCircuit(std::unordered_map<std::string, std::list<std::string>> adj) {
    std::vector<std::string> circuit;

    if (!adj.empty()) {
        dfs(adj.begin()->first, adj, circuit);
        std::reverse(circuit.begin(), circuit.end());
    }

    return circuit;
}

int main() 
{
    std::unordered_map<std::string, std::list<std::string>> adj;

    // Graph with Eulerian Path:
    adj["Rome"] = {"Instanbul", "Berlin"};
    adj["Instanbul"] = {"Rome", "Berlin", "Madrid", "Paris"};
    adj["Berlin"] = {"Rome", "London", "Paris", "Instanbul"};;
    adj["Paris"] = {"Instanbul", "Berlin", "London", "Madrid"};
    adj["London"] = {"Berlin", "Paris", "Madrid"};
    adj["Madrid"] = {"Instanbul", "London", "Paris"};

    // Assuming graph has a valid Eulerian circuit:
    std::vector<std::string> circuit = eulerianCircuit(adj);

    for (const auto& s : circuit) {
        std::cout << s << " ";
    }

    return 0;
}