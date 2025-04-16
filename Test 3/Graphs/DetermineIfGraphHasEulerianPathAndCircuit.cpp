#include <unordered_map>
#include <list>
#include <string>
#include <unordered_set>
#include <iostream>

bool hasEulerianPathDirected(const std::unordered_map<std::string, std::list<std::string>>& adj) {
    std::unordered_map<std::string, int> inDegree, outDegree;

    for (const auto& [u, neighbors] : adj) {
        outDegree[u] += neighbors.size();
        for (const std::string& v : neighbors) {
            inDegree[v]++;
            if (!outDegree.count(v)) outDegree[v] = 0;
        }
        if (!inDegree.count(u)) inDegree[u] = 0;
    }

    int startCandidates = 0, endCandidates = 0;
    for (const auto& [v, _] : adj) {
        int out = outDegree[v];
        int in  = inDegree[v];
        if (out - in == 1) startCandidates++;
        else if (in - out == 1) endCandidates++;
        else if (in != out) return false;
    }

    return (startCandidates == 0 && endCandidates == 0) ||
           (startCandidates == 1 && endCandidates == 1);
}

bool hasEulerianPathUndirected(const std::unordered_map<std::string, std::list<std::string>>& adj) {
    std::unordered_map<std::string, int> degree;

    for (const auto& [u, neighbors] : adj) {
        degree[u] += neighbors.size();
        for (const std::string& v : neighbors) {
            degree[v]++;
        }
    }

    int oddCount = 0;
    for (const auto& [v, deg] : degree) {
        if (deg % 2 != 0) oddCount++;
    }

    return oddCount == 0 || oddCount == 2;
}

int main()
{
    std::unordered_map<std::string, std::list<std::string>> adj1;
    std::unordered_map<std::string, std::list<std::string>> adj2;
    std::unordered_map<std::string, std::list<std::string>> adj3;
    std::unordered_map<std::string, std::list<std::string>> adj4;

    // 1. Directed Graph WITH Eulerian Path, but NO Eulerian Circuit
    adj1["A"] = {"B", "C"};
    adj1["B"] = {"D", "E"};
    adj1["C"] = {"B"};
    adj1["D"] = {"C", "F"};
    adj1["E"] = {"D"};
    adj1["F"] = {};

    // 2. Directed Graph WITH both Eulerian Path and Circuit
    adj2["A"] = {"B"};
    adj2["B"] = {"C"};
    adj2["C"] = {"D"};
    adj2["D"] = {"E"};
    adj2["E"] = {"A"};

    // 3. Undirected Graph WITH Eulerian Path, but NO Eulerian Circuit
    adj3["A"] = {"B", "C"};
    adj3["B"] = {"A", "C", "D"};
    adj3["C"] = {"A", "B", "D"};
    adj3["D"] = {"B", "C", "E"};
    adj3["E"] = {"D", "F"};
    adj3["F"] = {"E"};

    // 4. Undirected Graph WITH both Eulerian Path and Circuit
    adj4["A"] = {"B", "C"};
    adj4["B"] = {"A", "C", "D"};
    adj4["C"] = {"A", "B", "D"};
    adj4["D"] = {"B", "C"};

    return 0;
}